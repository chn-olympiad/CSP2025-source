#include<bits/stdc++.h>
using namespace std;
struct x
{
	int l,r;
};
string change2(int m)
{
	long long a[305],n=0;
	string s;
	while(m>0)
	{
		n++;
		a[n]=m%2;
		m/=2;
	}
	for(int i=n;i>=1;i--) s+=(char)(a[i]+'0');
	return s;
}
long long change10(string s)
{
	long long a=0,u=1;
	for(int i=s.size()-1;i>=0;i--)
	{
		a+=(s[i]-'0')*u;
		u*=2;
	}
	return a;
}
string xor2(string s1,string s2)
{
	string s;
	for(int i=1;i<=max(s1.size(),s2.size())-min(s1.size(),s2.size());i++) s+='0';
	if(s1.size()>s2.size()) s2=s+s2;
	else s1+=s;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]==s2[i]) s1[i]='0';
		else s1[i]='1';
	}
	return s1;
}
bool cmp(x y,x z)
{
	return y.l<z.l; 
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	x s[500005];
	long long n,k,sum=0,u;
	long long a[500005];
	cin>>n>>k;
	a[0]=0;
	//cout<<change2(n)<<" "<<change10(change2(n));
	for(int i=1;i<=n;i++)
	{
		cin>>u;
		string s1=change2(u);
		if(i==1) a[i]=u;
		else a[i]=change10(xor2(change2(a[i-1]),s1));
	}
	//for(int i=1;i<=n;i++) cout<<a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(change10(xor2(change2(a[i-1]),change2(a[j])))==k)
			{
				sum++;
				s[sum].l=i;
				s[sum].r=j;
				break;
			}
		}
	}
	sort(s+1,s+sum+1,cmp);
	int maxsum=0;
	for(int i=1;i<=sum;i++)
	{
		int maxr=0;
		int sum1=0;
		for(int j=i;j<=sum;j++)
		{
			if(s[j].r>s[j+1].r) continue;
			if(s[j].l>maxr)
			{
				sum1++;
				maxr=s[j].r;
			}
		}
		maxsum=max(maxsum,sum1);
	}
	cout<<maxsum;
	return 0;
}
