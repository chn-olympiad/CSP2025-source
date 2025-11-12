#include<bits/stdc++.h>
using namespace std;
long long n,q;
string s[200005][2];
string x,y;
long long ans=0;
void f(int l,int r)
{
	//if(l<0||r>=x.size()) return;
	string bf="",la="";
	for(long long i=l;i<=r;i++)
	{
		//bf[i-l]=x[i];
		//la[i-l]=y[i];
		bf+=x[i];
		la+=y[i];
		//cout<<bf[i];
	}
	//cout<<endl<<"bf:"<<bf<<endl<<"la:"<<la<<endl;
	for(long long i=0;i<n;i++)
	{
		if(bf==s[i][0]&&la==s[i][1])
		{
			ans++;
		}
	}
	return;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=0;i<n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	while(q--)
	{
		cin>>x>>y;
		long long l,r;
		long long ll=x.size();
		for(long long i=0;i<ll;i++)
		{
			if(x[i]!=y[i])
			{
				l=i;
				//cout<<l<<endl;
				break;
			}
		}
		for(long long i=n-1;i>=0;i--)
		{
			if(x[i]!=y[i])
			{
				r=i;
				//cout<<r<<endl;
				break;
			}
		}
		for(long long i=l;i>=0;i--)
		{
			for(long long j=r;j<ll;j++)
			{
				f(i,j);
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
