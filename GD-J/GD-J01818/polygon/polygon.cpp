#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],b[10005],n,k,bj,ans;
int mod=998244353 ;
void f(int s,int l,int m,int t)
{
	if(l>n)return;
	if(l>=3){if(s>m*2){ans++;ans%=mod;}}
	for(int i=t;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			f(s+a[i],l+1,max(m,a[i]),i+1);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{scanf("%d",&a[i]);if(a[i]==1)bj++;}
	if(bj==n)
	{
		cout<<(1+n-2)*(n-2)/2;
		return 0;
	}
	sort(a+1,a+n+1);
	f(0,0,0,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
