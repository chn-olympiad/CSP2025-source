#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int m[100001][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int mxit[100001],mnit[100001];
		for(int i=1;i<=n;i++){
		int mx=-1,mn=INT_MAX;
			for(int j=1;j<=3;j++){
				cin>>m[i][j];
				if(mx<=m[i][j]){
					mx=m[i][j];
					mxit[i]=j;
				}
				if(mn<=m[i][j]){
					mn=m[i][j];
					mnit[i]=j;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=m[i][mxit[i]];
		}
		cout<<ans;
	}
	
}
