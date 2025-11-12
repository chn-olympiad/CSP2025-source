#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;
long long p[5005],ans;
int n,l;
void f(int k,long long s,long long t)
{
//	cout<<s<<' '<<p[k]<<endl;
	if(k>n) return;
	if(t>=2&&s>p[k])
	{
		ans++;
	} 
	f(k+1,s+p[k],t+1);
	f(k+1,s,t);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	sort(p+1,p+n+1);
	f(1,0,0);
	cout<<ans<<endl;
	return 0;
}
