#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,sum,i,j,a[5050],b[5050];
bool f[5050];
string s;
map<string,bool> m;
bool fun(ll k)
{
	s="";
	ll i,su=0,ma=INT_MIN;
	for(i=1;i<=k;i++)
	{
		s+=to_string(b[i]);
		ma=max(ma,b[i]);
		su+=b[i];
	}
	return su>ma*2;
}
void dfs(ll k)
{
	ll i;
	for(i=1;i<=n;i++)
	{
		sum%=998244353;
		if(!f[i])
		{
			f[i]=true;
			b[k]=a[i];
			if(k>=3&&fun(k))
			{
				sort(s.begin(),s.end());
				if(m[s]==false)
				{
					m[s]=true;
					for(ll j=1;j<=k;j++)
					{
						cout<<b[j]<<" ";
					}
					cout<<endl;
					sum++;
				}
			}
			if(k<n)
			{
				dfs(k+1);
			}
			f[i]=false;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
