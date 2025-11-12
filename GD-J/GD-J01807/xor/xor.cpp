#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,k2,a[N],f,b[N],s=1,ans,w;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	k2=k;
	for(;k2>0;k2/=2)
		f++;
	f=pow(2,f);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k) ans++,b[i]=1;
		if(a[i]>=f && f>1) b[i]=1;
	}
	//cout<<f<<"\n";
	//for(int i=1;i<=n;i++)
	//	cout<<b[i]<<" ";
	b[n+1]=1;
	for(int i=1;s<=n;i++)
	{
		if(i>n+1) i=n+1;
		if(b[i]==1)
		{
			w=0,s++;
			if(s==i) s++;
		}
		else
		{
			w=w^a[i];
			if(w==k) ans++,s=i+1,w=0;
		}
	}
	cout<<ans;
	
	return 0;
}
