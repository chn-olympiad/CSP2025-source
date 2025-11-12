#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5;
int n,q,fl,;
string s[N][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	while(q--)
	{
		string x,y,bx="",by="";
		int ind=0;
		cin>>x>>y;
		for(int i=0;i<x.size();i++)if(x[i]!=y[i])ind=i;
		for(int i=0;i<=ind;i++)if(x[i]!=y[i])bx+=x[i],by+=y[i];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			long long fx=x.find(s[i][1]),fy=y.find(s[i][2]);
			if(fx>=0&&fx==fy)
			{
				int fbx=s[i][1].find(bx),fby=s[i][2].find(by);
				if(fbx>=0&&fbx==fby)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
