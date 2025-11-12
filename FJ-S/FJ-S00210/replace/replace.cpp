#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N_
#define P pair<ll,ll>
#define inf 1000000000000
ll n,q;
string s,t;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>t[i];
		
	}
	
	while(q--)
	{
		string u,v;
		cin>>u>>v;
		if(u.size()!=v.size()){
			cout<<0<<endl;
			continue;
		}
		bool f=0,h=1;
		string w="",g="";
		for(int i=0;i<u.size();i++)
		{
			if(u[i]!=v[i])
			{
				if(f&&u[i-1]==v[i-1]){
					cout<<0<<endl;
					h=0;
					break;
				}
				f=1;
				w=w+u[i];
				v=v+v[i];
			}
		}
		if(!h)continue;
		cout<<0<<endl;
	}
	return 0;
}

