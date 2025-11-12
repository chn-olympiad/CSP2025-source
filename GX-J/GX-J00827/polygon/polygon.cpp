#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int stk[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>stk[i];
	for(int i=3;i<=n;i++){
			for(int j=i-2;j>=1;j--){
				int lenmax=-1,lenal=0;
				for(int k=j;k<=i;k++){
					lenmax=max(lenmax,stk[k]);
					lenal+=stk[k];
				}
				lenal/=2;
				if(lenal>lenmax){
					ans++;
				}
			}
	}
	printf("%d",ans%998244353);
	return 0;
}
