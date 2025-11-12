#include<bits/stdc++.h>
using namespace std;
#define N 200010

int n,q;
string s[N][2],t0,t1;



signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	
	while(q--)
	{
		cin>>t0>>t1;
		int len=t0.size();
		
		int l=-1,r=len;
		for(int i=0;i<len;i++)if(t0[i]!=t1[i])
		{
			if(l==-1)l=i;
			r=i;
		}
		
		cout<<"0\n";
	}
	
	
	return 0;
}
//Ê¹ÈËÎÕ³Ö 
