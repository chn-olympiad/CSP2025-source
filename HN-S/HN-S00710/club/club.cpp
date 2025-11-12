#include<bits/stdc++.h>
#define int long long
using namespace std;
const int kN=3e5+10,kM=1e5+10;

struct Node{int a,b,c;int maxx;};

bool Cmp(Node,Node);
int Cost(Node);

Node input[kN];Node temp[4][kN];

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--)
	{
		int n,ans=0;cin>>n;
		for(int i=1;i<=n;i++)
			cin>>input[i].a>>input[i].b>>input[i].c,input[i].maxx=max(input[i].a,max(input[i].b,input[i].c)),ans+=input[i].maxx;
		int cnt[4]={0,0,0,0};
		for(int i=1;i<=n;i++)
			if(input[i].maxx==input[i].a)temp[0][++cnt[0]]=input[i];
			else if(input[i].maxx==input[i].b)temp[1][++cnt[1]]=input[i];
			else temp[2][++cnt[2]]=input[i];
		int id=-1;
		if(cnt[0]>n/2)id=0;
		if(cnt[1]>n/2)id=1;
		if(cnt[2]>n/2)id=2;
		if(id==-1){cout<<ans<<endl;continue;}
		sort(temp[id]+1,temp[id]+cnt[id]+1,Cmp);
		for(int i=1;i<=cnt[id]-n/2;i++)ans-=Cost(temp[id][i]);
		cout<<ans<<endl;
	}
	return 0;
}

bool Cmp(Node a,Node b){return Cost(a)<Cost(b);}

int Cost(Node a)
{
	if(a.a==a.b&&a.a==a.maxx)return 0;
	if(a.b==a.c&&a.b==a.maxx)return 0;
	if(a.c==a.a&&a.c==a.maxx)return 0;
	int res=INT_MAX,flag=true;
	if(a.maxx!=a.a)res=min(res,a.maxx-a.a);
	if(a.maxx!=a.b)res=min(res,a.maxx-a.b);
	if(a.maxx!=a.c)res=min(res,a.maxx-a.c);
	return res;
}
