#include<bits/stdc++.h>
#define int long long
#define pir pair<int,int>
using namespace std;
const int N=2e6+5;
struct node{
	string x,y;
	int len;
	bool operator <(const node u)const{
		return len<u.len;
	}
}s[N];
int n,q,l[N],len[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i].x>>s[i].y,s[i].len=s[i].x.size();
	sort(s+1,s+n+1);
	for(int i=1;i<=q;i++)
	{
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){cout<<"0\n";continue;}
		else
		{
			int l=0,r=0,len=0;
			for(int j=0;j<x.size();j++)
				if(x[j]!=y[j]){l=j;break;}
			for(int j=x.size()-1;j>=0;j--)
				if(x[j]!=y[j]){r=j;break;}
			len=r-l+1;
			int L=1,R=n,id=-1;
			while(L<=R)
			{
				int mid=L+R>>1;
				if(s[mid].len>=len)id=mid,R=mid-1;
				else L=mid+1;
			}
			if(id==-1){cout<<"0\n";continue;}
			int res=0;
			for(int j=id;j<=n;j++)
			{
				if(s[j].len>x.size())break;
				int pos=0;
				for(int u=0;u<x.size();u++)
				{
					if(s[j].x[pos]==x[u]&&s[j].y[pos]==y[u])pos++;
					else pos=0;
					if(pos==s[j].x.size()-1)break;
				}
				if(pos==s[j].x.size()-1&&pos)res++;
				else if(pos==0&&x.size()==1&&s[j].x[0]==x[0]&&s[j].y[0]==y[0])res++;
			}
			cout<<res<<'\n';
		}
	}
	return 0;
}

