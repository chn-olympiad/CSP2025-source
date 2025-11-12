#include<bits/stdc++.h>
using namespace std;
int n,m,s,cnt;
int a[110];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0) s=a[i];
	}
	sort(a,a+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[cnt]==s){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[cnt]==s){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
		
	}
	return 0;
}
