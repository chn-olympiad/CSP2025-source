#include<bits/stdc++.h>
using namespace std;
int a[501];
const int mod=998244353;
long long A(int b)
{
	if(b<=0)return 1;
	long long ans=1;
	for(int i=b;i>=1;i--)
		ans=(ans*i)%mod;
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string st;
	cin>>n>>m>>st;
	bool ok=1,o=1;
	for(int i=0;i<n;i++){
		if(st[i]=='0')ok=0;
		if(st[i]=='1')o=0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	if(o){
		cout<<0;
		return 0;
	}
	if(n==m){
		if(!ok){
			cout<<0;
			return 0;
		}
		else ok=1;
	}	
	if(ok){
		cout<<A(n);
		return 0;
	}
	if(m==1){
		int c=-1;
		for(int i=0;i<n;i++)
			if(st[i]=='1')c++;
		long long ans=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=c;j++)ans=(ans*A(a[i]-1+j)%mod)*(A(n-(a[i]-1+j)-1)%mod)%mod;
			cout<<ans<<'\n';
		}
		cout<<ans;
		return 0;
	}
	int id[501];
	for(int i=1;i<=n;i++)id[i]=i;
	long long ans=0;
	do{
		int res=0,num=0;
		for(int i=1;i<=n;i++){
			if(st[i-1]=='0')num++;
			else{
				if(a[id[i]]>num)res++;
				else num++;
			}
		}
		if(res>=m)ans=(ans+1)%mod;
	}while(next_permutation(id+1,id+1+n));
	cout<<ans;
}
