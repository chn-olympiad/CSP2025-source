#include<iostream>
#include<algorithm>
using namespace std;
const int md=998244353;
int c[501],p[501],cnt[501];
char s[501];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long ans=0;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		cnt[i]=i;
	}
	int k=0,r=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='1'&&k<c[i])
			r++;
		else 
			k++;
	}
	if(r>=m)
		ans++;
	int ct=1;
	while(next_permutation(cnt+1,cnt+n+1))
	{
		int k=0,r=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='1'&&k<c[cnt[i]])
				r++;
			else 
				k++;
		}
		if(r>=m)
			ans++;
		ct++;
	}
	cout<<ans;
	/*int k1=0,k2=1;
	for(int i=0;i<n;i++)
{
	if(s[i]=='0')
{
	p[k2]=k1;
	k2++;
	}
	else
	k1++;
	}
	while(k2<=n)
{
	p[k2]=k1;
	k2++;
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//freopen
//T4 employ
//Luogu: WOLFSTAR(1044658)
//CSP-S2025 rp++
//NOIP2025 rp++
//来てくれてありがとう！

//组合数学也太阴了，只能暴力拿10分了