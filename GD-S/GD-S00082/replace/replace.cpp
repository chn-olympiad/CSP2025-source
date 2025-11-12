#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,Q;
map<string,int> mp1,mp2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)
	{
		string x,y;
		cin>>x>>y;
		mp1[x]=i,mp2[y]=i;
	}
	while(Q--)
	{
		string x,y;
		cin>>x>>y;
		int len=x.size(),L=len-1,R=0;
		for(int i=0;i<len;i++)
			if(x[i]!=y[i])
			{
				L=i-1;
				break;
			}
		for(int i=len-1;~i;i--)
			if(x[i]!=y[i])
			{
				R=i+1;
				break;
			}
		int ans=0;
		for(int i=0;i<=L;i++)
			for(int j=R;j<len;j++)
			{
				string A=x,B=y;
				A=A.substr(i+1,j-i-1);
				B=B.substr(i+1,j-i-1);
				if(mp1[A]==mp2[B]) ++ans;
			}
		cout<<ans<<"\n";
	}
	return 0;
}
