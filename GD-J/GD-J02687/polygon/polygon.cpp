#include<bits/stdc++.h>
using namespace std;
const int MX=5e4+5;
const long MOD=998244353;
int n,a[MX],ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
 memset(a,0,sizeof(a));
	cin>>n;	
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans+=a[i]*a[i];
		ans=ams%MOD;
	}
	cout<<ans;
	return 0;
} 
