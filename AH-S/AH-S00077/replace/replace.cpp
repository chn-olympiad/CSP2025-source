#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	string xx,yy;
}a[N];
int ans=0;
int q;
int n;
int o;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string x,y;
		cin>>x>>y;
		a[i]={x,y};
	}
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size())
		{
			cout<<0<<endl;
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			o=x.find(a[i].xx);
			if(o==-1)continue;
			string l=x.substr(0,o);
			int len=x.size();
			string r=x.substr(o+a[i].xx.size(),len-(o+a[i].xx.size()));
			string oo=l+a[i].yy+r;
			if(oo==y)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
