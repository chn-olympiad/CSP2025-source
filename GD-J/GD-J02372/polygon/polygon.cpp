#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,now,fg=0,mod=998244353,t[5010],so[5010],s[5010],q[5010]={0};
long long al=0,ans=0;
int f(int l,int r,int a,int num)
{
	int m=0;
	if(num<=0) return 0;
	for(int i=l;i<=r;i++){
		if(so[i]<a){
			m++;
			m+=f(i+1,r,a-so[i],num--);
		}
		else break;
	}
	return m%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		t[s[i]]++;
		al+=s[i];
		so[i]=s[i];
	}
	sort(so+1,so+n);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+so[i];
	}
	now=3;
	while(now<=n){
		if(so[now]*2<q[now]){
			ans++;
			ans+=f(1,now-1,q[now]-so[now]*2,now-2-1);
		}
		ans%=mod;
		now++;
	}
	cout<<ans;
	return 0;
}
