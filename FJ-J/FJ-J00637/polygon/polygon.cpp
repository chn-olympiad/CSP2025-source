#include<bits/stdc++.h>
using namespace std;
int MOD=998244353;
int n,cnt,cunt,cont;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int k=1;k<=n-i+1;k++){
			cunt=0;
			cont=0;
			for(int j=1;j<k+i;j++){
				cunt+=a[j];
			}
			for(int j=1;j<k+i;j++){
				cont=max(a[j],cont);
			}
			if(cunt>cont){
				cnt++;
			}
		}
	}
	cout<<cnt%MOD;
	return 0;
}
