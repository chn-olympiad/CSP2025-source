#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
using ll=long long;
#define File_IO 1
#define debug 0
int gcd(int a,int b)
{
	if(b)while((a%=b)&&(b%=a));
	return a+b;
}
void Ex_gcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		//1a+0=gcd(a,0)
		return;
	}
	Ex_gcd(b,a%b,y,x);
	y-=std::floor(a/b)*x;
	//b(x1)+(a-floor(a/b)*b)(y1)=gcd(a,b)
	//a(y1)+b(x1-floor(a/b)*y1)=gcd(a,b)
}
const int maxn=1e4+1,maxm=1e6+1,maxk=11;
int n,m,k;
struct bians
{
	int u,v;
	ll w;
	bians(int u_=0,int v_=0,ll w_=0)
	{
		u=u_;
		v=v_;
		w=w_;
	}
};
vector<bians>bian_at_first;
ll c[maxk],a[maxk][maxn];
struct bingchaji
{
	vector<int>f;
	bingchaji(int n=0)
	{
		f.clear();
		f.resize(n+1);
		reset(n);
	}
	void reset(int n)
	{
		for(int i=0;i<=n;i++)
		{
			f[i]=i;
		}
	}
	int find(int x)
	{
		stack<int>s;
		while(x!=f[x])
		{
			s.push(x);
			x=f[x];
		}
		while(!s.empty())
		{
			f[s.top()]=x;
			s.pop();
		}
		return x;
	}
	bool merge(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y)return false;
		f[x]=y;
		return true;
	}
};
vector<bians>bian;
ll solve(const int town,bingchaji &b)
{
	ll wer=0;
	b.reset(n+k);
	bian=bian_at_first;
	int cnt=n;
	for(int j=1;j<=k;j++)
	{
		if(town&(1<<(j-1)))
		{
			wer+=c[j];
			cnt++;
			for(int i=1;i<=n;i++)
			{
				bian.push_back(bians(i,j+n,a[j][i]));
			}
		}
		continue;
	}
	cnt-=1;//±ß=µã-1 
	sort(bian.begin(),bian.end(),[](const bians &x,const bians &y)
	{
		return x.w<y.w;
	});
	for(const bians &i:bian)
	{
		if(cnt<=0)break;
		if(b.merge(i.u,i.v))
		{
			wer+=i.w;
			cnt--;
			#if debug
			cout<<i.u<<' '<<i.v<<' '<<i.w<<endl;
			#endif
		}
	}
	#if debug
	cout<<"cnt="<<cnt<<endl;
	#endif
	return wer;
}
ll ans=1e16;
int main()
{
	#if File_IO
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif
	cin>>n>>m>>k;
	bingchaji b(n+k+1);
	bian_at_first.resize(m+1);
	for(int i=1;i<=m;i++)
	{
		cin>>bian_at_first[i].u>>bian_at_first[i].v>>bian_at_first[i].w;
	}
	sort(bian_at_first.begin(),bian_at_first.end(),[](const bians &x,const bians &y)
	{
		return x.w<y.w;
	});
	#if debug
	for(int i=1;i<=m;i++)
	{
		cout<<bian_at_first[i].u<<' '<<bian_at_first[i].v<<' '<<bian_at_first[i].w<<endl;
	}
	#endif
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int j=0;j<(1<<k);j++)
	{
		ans=min(ans,solve(j,b));
	}
	cout<<ans;
	return 0;
}
