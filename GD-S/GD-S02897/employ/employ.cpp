#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
char s[505];
long long zx(int l,int r){
	long long w=1;
	for(int i=r;i>=r-l;i--) if(i!=0) w=(w*i)%mod;
	return w;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	long long ans=0;
	for(int i=m;i<=n;i++){
		ans=(ans+zx(n-i+1,n))%mod;
		//cout<<zx(1,n)<<' '<<ans<<' '<<zx(n-i+1,n)<<endl;
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
