#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],cnt=0;int ans=0,g;
int y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int t;cin>>t;
		a[t]=1;
		if(i==1)g=t;
	}
	for(int i=100;i>=1;i--){
		if(a[i]==1)cnt++;
		if(i==g)break;
	}
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				ans++;
				if(ans==cnt){
					cout<<i<<" "<<j;
					break;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				ans++;
				if(ans==cnt){
					cout<<i<<" "<<j;
					break; 
				}
			}
		}
		if(ans>=cnt)break;
	}
	return 0;
}
