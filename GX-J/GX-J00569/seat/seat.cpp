#include<bits/stdc++.h>
using namespace std;
int n,m,ans,cnt;
int a[10001],s[101][101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		cnt++;
	    if(a[i]==ans){
			break;
		}
	}
	int k=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
		    if(i%2==1)s[j][i]=k;
		    else s[n-j+1][i]=k;
		    k++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==cnt)cout<<j<<" "<<i;
		}
	}
    return 0;
}
