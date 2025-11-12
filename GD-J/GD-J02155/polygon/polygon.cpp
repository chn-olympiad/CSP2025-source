#include <bits/stdc++.h>
using namespace std;
using ll=long long;
long long n,p[5005],ans,psk[5005][5005];
int main(){
	freopen("polygon.out","w",stdout);
	freopen("polygon.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}sort(p+1,p+1+n);
	for(int i=3;i<=n;i++){
		for(int k=1;k<=105;k++){
			for(int j=1;j<=105;j++) psk[j][k]=0;
		}psk[1][0]=1;
		for(int j=1;j<=i;j++){
			for(int k=0;k<=p[i];k++){
				psk[j+1][k]+=psk[j][k];
				psk[j+1][min(p[i],k+p[j])]+=psk[j][k];
			}
		}ans+=psk[i][p[i]];
	}cout<<ans/2;
}
