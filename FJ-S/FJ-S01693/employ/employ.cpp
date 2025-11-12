#include<bits/stdc++.h>
using namespace std;
int n,m,ll;string s1;
long long sum=0,sum2=0,sum1,c[1001],d;int l[1001]={ },s[1001];
long long a(long long b);
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s1;
	cin>>n>>m>>s1;ll=n+1;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		s[i]=(int)(s1[i]-'0');
	}
	a(n);
	cout<<sum2<<endl;
	return 0;
}
long long a(long long b)
{
	for(int i=0;i<n;i++)
	{
		if(l[i]!=1)
		{
			d=ll-b-1;
			if(s[d]==1&&c[i]>=d)
			sum++;
			if(b!=1)
			{
				l[i]=1;
				a(b-1);
				l[i]=0;
			}
			else
			{    
				if(sum>=m)
				{
					sum2++;
					if(sum2>=998244353)
					sum2-=998244353;					
				}
				l[n]={ };
			}//last
			if(s[d]==1&&c[i]>=d)
			sum--;	
		}	
	}
	return 0;
}
