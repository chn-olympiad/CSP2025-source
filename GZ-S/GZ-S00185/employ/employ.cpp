//GZ-S00185 华东师范大学附属贵阳学校 彭梓垚 
#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod=998244353; 
int n,m,s[N],c[N];
map<int,int> a;
long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m>n/2) m=n-m;
	for(int i=n,j=2;i>=n-m+1;i--,j++){
		if(ans*i%j!=0&&j<=m) a[j]--,a[i]++; 
		else if(j<=m) ans*=i,ans/=j,ans%=mod;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(ans%j==0&&a[j]<0) ans/=j,a[j]++;
			if(a[i]>0) ans*=i,ans%=mod,a[i]--;
		}
	}
	for(int i=1;i<=n;i++) if(a[i]>0) ans%=mod,ans*=i;
	cout<<ans%mod<<endl;
	return 0;
}
