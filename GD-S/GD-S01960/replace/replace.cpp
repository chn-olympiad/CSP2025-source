#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,k,i,j,x,y,fa[10005],cnt,len,ans,l,r,nn;
bool bbb=true;
string s[2][200005],a[200005],b[200005];
struct node{
	ll l,r;
};
node ps(ll l,ll r)
{
	node v;
	v.l=l; v.r=r;
	return v;
}
vector<node> mv[10000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>s[0][i]>>s[1][i];
		if(s[0][i].size()>len) len=s[0][i].size();
		if(bbb) for(j=0;j<s[0][i].size();j++) if(s[0][i][j]!='a'&&s[0][i][j]!='b'||s[1][i][j]!='a'&&s[1][i][j]!='b')
		{
			bbb=false;
			break;
		}
	}
	for(i=1;i<=q;i++)
	{
		cin>>a[i]>>b[i];
		if(bbb) for(j=0;j<a[i].size();j++) if(a[i][j]!='a'&&a[i][j]!='b')
		{
			bbb=false;
			break;
		}
		if(bbb) for(j=0;j<b[i].size();j++) if(b[i][j]!='a'&&b[i][j]!='b')
		{
			bbb=false;
			break;
		}
	}
	if(bbb)
	{
		for(i=1;i<=n;i++)
		{
			x=s[0][i].find("b"); y=s[1][i].find("b");
			//cout<<y-x+len<<":"<<x<<","<<s[0][i].size()-x<<"\n";
			mv[y-x+len].push_back(ps(x,s[0][i].size()-x));
		}
		for(i=1;i<=q;i++)
		{
			x=a[i].find("b"); y=b[i].find("b");
			y=y-x+len;
			if(y<0||y>2*len||a[i].size()!=b[i].size())
			{
				cout<<"0\n";
				continue;
			}
			ans=0; r=a[i].size()-x;
			//cout<<y<<":"<<x<<","<<r<<"   ";
			for(j=0;j<mv[y].size();j++) if(x>=mv[y][j].l&&r>=mv[y][j].r) ans++;
			cout<<ans<<"\n";
		}
		return 0;
	}
	for(i=1;i<=q;i++)
	{
		if(a[i].size()!=b[i].size())
		{
			cout<<"0\n";
			continue;
		}
		for(j=0;j<a[i].size();j++) if(a[i][j]!=b[i][j])
		{
			l=j;
			break;
		}
		for(j=a[i].size()-1;j>=0;j--) if(a[i][j]!=b[i][j])
		{
			r=j;
			break;
		}
		ans=0;
		for(j=1;j<=n;j++) 
		{
			nn=s[0][j].size();
			if(nn<r-l+1) continue;
			for(k=max(0ll,l-nn+1);k<=r;k++) if(a[i].substr(k,nn)==s[0][j]) if(b[i].substr(k,nn)==s[1][j])
			{
				ans++;
				//cout<<k<<"~"<<k+nn-1<<" "<<s[0][j]<<"->"<<s[1][j]<<"\n";
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
