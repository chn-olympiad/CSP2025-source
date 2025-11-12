#include<bits/stdc++.h>
#define int long long
using namespace std;
#define pc putchar
#define we(x) (write(x),pc('\n'))
#define ws(x) (write(x),pc(' '))
#define rep(i,x,y) for(int i=x;i<=y;i++)
const int N=1e5,M=1e5,mod=998244353;
inline void read(int &x)
{
	x=0;
	register char ch;
	while((ch=getchar())<'0'||ch>'9');
	do
	{
		x=(x<<1)+(x<<3)+ch-'0';
	}while((ch=getchar())>='0'&&ch<='9');
}
inline void write(int x)
{
	if(x==0)
	{
		pc('0');
		return;
	}
	if(x>=10)write(x/10);
	pc(x%10+'0');
}
int cnt[4];
struct node
{
	int a,b,c,id;
	int ab,ac,bc;
}a[N+5];
vector<node>A[4];
bool cmp(node x,node y)
{
	if(max(x.a,max(x.b,x.c))==max(y.a,max(y.b,y.c)))
	{
		if(x.a==y.a)
		{
			if(x.b==x.b)return x.c>y.c;
			return x.a>y.b;
		}
		return x.a>y.a;
	}
	return max(x.a,max(x.b,x.c))>max(y.a,max(y.b,y.c));
}
bool cmpab(node x,node y)
{
	return x.ab>y.ab;
}
bool cmpbc(node x,node y)
{
	return x.bc>y.bc;
}
bool cmpac(node x,node y)
{
	return x.ac>y.ac;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		int n;
		read(n);
		rep(i,1,3)cnt[i]=0,A[i].clear();
		rep(i,1,n)
		{
			read(a[i].a),read(a[i].b),read(a[i].c);
		//	if(T==1)ws(a[i].a);
			a[i].ac=a[i].c-a[i].a;
			a[i].ab=a[i].b-a[i].a;
			a[i].bc=a[i].c-a[i].b;
		}
		sort(a+1,a+1+n,cmp);
		rep(i,1,n)
		{
			node x=a[i];
			int tt=max(x.a,max(x.b,x.c));
			if(x.a==tt)
			{
				if(cnt[1]<n/2)++cnt[1],a[i].id=1;
				else
				{
					if(x.b==tt&&cnt[2]<n/2)++cnt[2],a[i].id=2;
					else if(x.c==tt&&cnt[3]<n/2)++cnt[3],a[i].id=3;
					else
					{
						if(x.b>x.c&&cnt[2]<n/2||cnt[3]==n/2)++cnt[2],a[i].id=2;
						else ++cnt[3],a[i].id=3;
					}
				}
			}
			if(x.b==tt)
			{
				if(cnt[2]<n/2)++cnt[2],a[i].id=2;
				else
				{
					if(x.a==tt&&cnt[1]<n/2)++cnt[1],a[i].id=1;
					else if(x.c==tt&&cnt[3]<n/2)++cnt[3],a[i].id=3;
					else
					{
						if(x.a>x.c&&cnt[1]<n/2||cnt[3]==n/2)++cnt[1],a[i].id=1;
						else ++cnt[3],a[i].id=3;
					}
				}
			}
			if(x.c==tt)
			{
				if(cnt[3]<n/2)++cnt[3],a[i].id=3;
				else
				{
					if(x.a==tt&&cnt[1]<n/2)++cnt[1],a[i].id=1;
					else if(x.b==tt&&cnt[2]<n/2)++cnt[2],a[i].id=2;
					else
					{
						if(x.a>x.b&&cnt[1]<n/2||cnt[2]==n/2)++cnt[1],a[i].id=1;
						else ++cnt[2],a[i].id=2;
					}
				}
			}
		//	cout<<"ff"<<a[i].id<<endl;
		}
		rep(i,1,n)A[a[i].id].push_back(a[i]);
		int ans=0;
		sort(A[1].begin(),A[1].end(),cmpab);
		sort(A[2].begin(),A[2].end(),cmpab);
		int maxn=min(A[1].size(),A[2].size());
		rep(i,0,maxn-1)
		{
			//cout<<A[1][i].ab<<" "<<A[2][cnt[2]-i-1].ab<<endl;
			if(A[1][i].ab>A[2][cnt[2]-i-1].ab)
				swap(A[1][i],A[2][cnt[2]-i-1]);
		}
		sort(A[1].begin(),A[1].end(),cmpac);
		sort(A[3].begin(),A[3].end(),cmpac);
		maxn=min(A[1].size(),A[3].size());
		rep(i,0,maxn-1)
		{
		//	if(A[1][i].a==3471)cout<<"fff"<<A[1][i].ac<<" "<<A[3][cnt[3]-i-1].ac<<endl;
			if(A[1][i].ac>A[3][cnt[3]-i-1].ac)swap(A[1][i],A[3][cnt[3]-i-1]);
		}
		sort(A[2].begin(),A[2].end(),cmpbc);
		sort(A[3].begin(),A[3].end(),cmpbc);
		maxn=min(A[2].size(),A[3].size());
		rep(i,0,maxn-1)
		{
			if(A[2][i].bc>A[3][cnt[3]-i-1].bc)
			{
				//cout<<A[2][i].bc<<" "<<A[3][cnt[3]-i-1].bc<<endl;
			//	ws(A[3][cnt[3]-i-1].bc);
				swap(A[2][i],A[3][cnt[3]-i-1]);
			}
		}
		//ws(A[1].size()),ws(A[2].size()),ws(A[3].size());
		// for(node i:A[1])ans+=i.a,ws(i.a);
		// pc('\n');
		// for(node i:A[2])ans+=i.b,ws(i.b);
		// pc('\n');
		// for(node i:A[3])ans+=i.c,ws(i.c);
		// pc('\n');
		for(node i:A[1])ans+=i.a;
		for(node i:A[2])ans+=i.b;
		for(node i:A[3])ans+=i.c;
		we(ans);
	}
}