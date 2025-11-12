#include<bits/stdc++.h>
using namespace std;
int n,m,hua;
int sum,cnt;
int a[1005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++)cin>>a[i];
	hua=a[1];
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				cnt++;
				if(a[cnt]==hua){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(a[cnt]==hua){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
// q.7
//~l2
//ÉÏÉÆÈôË® 
//4 3 6 4 
