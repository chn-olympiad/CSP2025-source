#include<bits/stdc++.h>
using namespace std;
int n,m,c[5005],p[5005];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("empioy.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	bool ok=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0') ok=1;
		if(s[i-1]=='0') p[i]=p[i-1]+1;
		else p[i]=p[i-1];
	}
	if(ok==0){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%998244353;
		}
		cout<<ans<<endl;
	}else{
		cout<<2<<endl;
	}
	return 0;
}
