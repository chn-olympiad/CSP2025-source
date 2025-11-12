#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],s[500010],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long l=i,r=i,f=0;
		while(r<=n)
		{
			if(int(s[r]^s[l-1])==k)
			{
				l=r+1;
				f++;
			}
			r++;
		}
		ans=max(ans,f);
	}
	cout<<ans;
	return 0;
}
