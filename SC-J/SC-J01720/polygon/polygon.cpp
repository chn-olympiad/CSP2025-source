#include<bits/stdc++.h>
using namespace std;
int const N=5e3+1;
int const MOD=998244353;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out ","w",stdout);
	int a[N]={};
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		int maxa=0,he=0;
		for(int k=1;k<=n;k++){
			for(int j=k;j<=n;j++){
				maxa=max(maxa,a[j]);
				he+=a[j];
			}
		}
		if(he>2*maxa){
			cnt=(cnt+1)%MOD;
			cout<<he<<" "<<maxa<<"\n";
			
		}
		maxa=0,he=0;
	}
	cout<<cnt;
	return 0;
}