#include<bits/stdc++.h>
using namespace std;
int n,m,s[105],a[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s[1];
	int num=s[1];
	for(int i=2;i<=n*m;i++){
		cin>>s[i];
	}
	sort(s+1,s+n*m+1,cmp);	
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				cnt++;
				if(s[cnt]==num){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				cnt++;
				if(s[cnt]==num){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
