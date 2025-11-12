/*
#include<bits/stdc++.h>
#define max(a,b)(a>=b?a:b)
#define min(a,b)(a>=b?b:a)
#define int long long

using namespace std;
const int maxn=2e5+10;
struct st{
	int c1,c2,c3;
	int maxlike;
	int club;
}a[maxn];
inline bool check(st p,st q)
{
	return(p.maxlike>=q.maxlike);
}
inline void solve(){
	int n;cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].c1>>a[i].c2>>a[i].c3;
		a[i].maxlike=max(a[i].c1,max(a[i].c2,a[i].c3));
	}
	
	sort(a+1,a+n,check);
	
	
	return;
}
signed main(){
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	
	int t;cin>>t;
	while(t--)solve(); 
	return 0;
} 
*/
#include<bits/stdc++.h>
#define max(a,b)(a>=b?a:b)
#define int long long

using namespace std;
const int maxn=2e5+10;

inline int check(int a,int b,int c,
									int a1,int b1,int c1)
{
	int cnt[10]={0,0,0,0,0,0,0,0,0,0};
	cnt[1]=a+b1;
	cnt[2]=a+c1;
	cnt[3]=b+a1;
	cnt[4]=b+c1;
	cnt[5]=c+a1;
	cnt[6]=c+b1;
	return max(cnt[1],max(cnt[2],max(cnt[3],max(cnt[4],max(cnt[5],cnt[6])))));
}

inline void solve( void )
{
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i+=2)
	{
		int a,b,c,d,e,f;
		cin>>a>>b>>c>>d>>e>>f;
		cnt+=check(a,b,c,d,e,f);
	}
	cout<<cnt<<"\n";
	
	return;
}
//Ren5Jie4Di4Ling5%
signed main( void )
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	
	int t;cin>>t;
	while(t--)solve();
	return 0;
}

/*
#include<bits/stdc++.h>
#define max(a,b)(a>=b?a:b)
#define int long long

using namespace std;
const int maxn=2e5+10;
int a[maxn][4];
int d[maxn];
inline void solve()
{
	int c1,c2,c3;
	c1=c2=c3=0;
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=a[i][d[i]];
	}
	cout<<cnt<<"\n";
	return;
}
signed main( void )
{
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
*/
/*
#include<bits/stdc++.h>
#define int long long

using namespace std;
inline void solve( void )
{
	
	return;
}
signed main( void )
{
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	
	int t;cin>>t;
	while(t--)solve();
	
	return 0;
}
*/
/*
#include<bits/stdc++.h>
#define int long long

using namespace std;
const int maxn=2e5+10;
struct node{int a,id;
bool vis=false;
};
node c1[maxn],c2[maxn],c3[maxn];
int n;
bool vis[maxn];
inline bool cmp(node x,node y)
{
	return x.a>=y.a;
}
inline void solve( void )
{
	cin>>n;
	int max1,max2,max3;
	int cnt1=0,cnt2=0,cnt3=0;
	max1=max2=max3=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c1[i].a>>c2[i].a>>c3[i].a;
		c1[i].id=c2[i].id=c3[i].id=i;
	}
	sort(c1+1,c1+1+n,cmp);
	sort(c2+1,c2+1+n,cmp);
	sort(c3+1,c3+1+n,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(c1[i].id!=c2[i].id&&c2[i].id!=c3[i].id&&c1[i].id!=c3[i].id&&(cnt1<n/2&&cnt2<n/2&&cnt3<n/2))
		{
			c1[i].vis=c2[i].vis=c3[i].vis=true;
			cnt+=c1[i].a+c2[i].a+c3[i].a;
			cnt1++,cnt2++,cnt3++;
		}
		else if(c1[i].id==c2[i].id&&c2[i].id==c3[i].id&&c1[i].id==c3[i].id)
		{
			if(c1[i].a==max(c1[i].a,max(c2[i].a,c3[i].a)))c1[i].vis=true;
			else if(c2[i].a==max(c1[i].a,max(c2[i].a,c3[i].a)))c2[i].vis=true;
			else c3[i].vis=true;
			cnt+=max(c1[i].a,max(c2[i].a,c3[i].a));
		}
		else{
			if(c1[i].id==c2[i].id&&(cnt1<n/2&&cnt3<n/2))
			{
				c1[i].vis=c3[i].vis=true;
				cnt+=(c1[i].a+c3[i].a);
				cnt1++,cnt3++;
			}
			else if(c1[i].id==c3[i].id&&(cnt1<n/2&&cnt2<n/2))
			{
				c1[i].vis=c2[i].vis=true;
				cnt+=(c1[i].a+c2[i].a);
				cnt1++,cnt2++;
			}
			else 
			{
				c2[i].vis=c3[i].vis=true;
				cnt+=(c2[i].a+c3[i].a);
				cnt1++,cnt2++;
			}
		}
	}
	cout<<cnt<<"\n";
	return;
}
signed main( void )
{
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	
	int t;cin>>t;
	while(t--)solve();
	
	return 0;
}
*/
/*
#include<bits/stdc++.h>
#define int long long

using namespace std;
signed main( void )
{
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	
	
	return 0;
}
*/
