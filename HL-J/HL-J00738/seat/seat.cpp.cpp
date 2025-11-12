#include<bits/stdc++.h>
using namespace std;
int n,m,s[1000],maxn,a[105][105];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i]>maxn){
				s[i]=maxn;
			}
			if(i>1&&i<=n){
				maxn=a[1][n];
			}
			if(i>=n+1&&i<=2*n){
				maxn=a[2][n];
			}
			if(i>2*n+1&&i<=3*n){
				maxn=a[3][n];
			}
		}
	}
	cout<<maxn;
    return 0;
}
