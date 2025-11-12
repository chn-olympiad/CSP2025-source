#include<bits/stdc++.h>
using namespace std;
#define ll long long
priority_queue<ll,vector<ll>,greater<ll> >sh1;
priority_queue<ll,vector<ll>,greater<ll> >sh2;
priority_queue<ll,vector<ll>,greater<ll> >sh3;
int len1,len2,len3;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	ll ans=0;
	while(T--)
	{
		int n;
		cin >> n;
		int ln=n/2;
		for(int i=1;i<=n;i++)
		{
			ll x,y,z;
			cin >> x >> y >> z;
			int ls=0;
			if((x>=y && y>=z) || (z>=y && y>=x))
			{
				ls=y;
			}
			else if((y>=x && x>=z) || (z>=x && x>=y))
			{
				ls=x;
			}
			else
			{
				ls=z;
			}
			if(x>=y && x>=z)
			{
				ans+=x;
				if(len1<ln)
				{
					len1++;
					sh1.push(x-ls);
				}
				else
				{
					int l=sh1.top();
					if(l<x-ls)
					{
						ans-=l;
						sh1.pop();
						sh1.push(x-ls);
					}
					else
					{
						ans-=(x-ls);
					}
				}
			}
			else if(y>=x && y>=z)
			{
				ans+=y;
				if(len2<ln)
				{
					len2++;
					sh2.push(y-ls);
				}
				else
				{
					int l=sh2.top();
					if(l<y-ls)
					{
						ans-=l;
						sh2.pop();
						sh2.push(y-ls);
					}
					else
					{
						ans-=(y-ls);
					}
				}
			}
			else
			{
				ans+=z;
				if(len3<ln)
				{
					len3++;
					sh3.push(z-ls);
				}
				else
				{
					int l=sh3.top();
					if(l<z-ls)
					{
						ans-=l;
						sh3.pop();
						sh3.push(z-ls);
					}
					else
					{
						ans-=(z-ls);
					}
				}
			}
		}
		cout << ans <<"\n";
		ans=0;
		len1=len2=len3=0;
		while(!sh1.empty()) sh1.pop();
		while(!sh2.empty()) sh2.pop();
		while(!sh3.empty()) sh3.pop();
	}
	return 0;
}
