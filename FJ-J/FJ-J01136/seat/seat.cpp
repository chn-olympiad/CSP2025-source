#include<bits/stdc++.h>
using namespace std;
long long f(long long a,long long b)
{
	if(a%b==0) return a/b;
	else return (a/b)+1;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long s[m*n];
	for(long long i=0;i<m*n;i++)
	{
		cin>>s[i];
	}
	long long a=s[0];
	sort(s,s+m*n);
	long long w;
	for(long long i=0;i<m*n;i++)
	{
		if(s[i]==a)
		{
			w=m*n-i;
			break;
		}
	}
	long long ans1,ans2;
	ans1=f(w,n);
	ans2=w%n;
	if(ans2==0) ans2=n;
	if(f(w,n)%2==0) ans2=n-ans2+1;
	cout<<ans1<<" "<<ans2;
	return 0;
}
