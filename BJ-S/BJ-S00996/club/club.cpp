#include <bits/stdc++.h>
#define int long long
#define fastread ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int qpow(int x,int a,int md){int res=1;while(a){if(a&1) res=(res*x)%md;x=(x*x)%md;a>>=1;}return res;}
using namespace std;
#define maxn 100009


int n;
struct node{int x,y,z;}a[maxn];

int cnt1,cnt2,cnt3;
int ans=0;
int sum=0;
void dfs(int now)
{
    if(now==n+1)
    {
        sum=max(sum,ans);
        return ;
    }   
    if(cnt1<n/2&&!(a[now].x<a[now].y&&a[now].x<a[now].z))
    {
        cnt1++;
        ans+=a[now].x;
        dfs(now+1);
        ans-=a[now].x;
        cnt1--;
    }
    if(cnt2<n/2&&!(a[now].y<a[now].x&&a[now].y<a[now].z))
    {
        cnt2++;
        ans+=a[now].y;
        dfs(now+1);
        ans-=a[now].y;
        cnt2--;
    }
    if(cnt3<n/2&&!(a[now].z<a[now].x&&a[now].z<a[now].y))
    {
        cnt3++;
        ans+=a[now].z;
        dfs(now+1);
        ans-=a[now].z;
        cnt3--;
    }
}

void solve()
{
    int mxa=0,mxb=0;
    cnt1=0,cnt2=0,cnt3=0;
    ans=0;sum=0;
	for(int i=1;i<=n;i++) a[i]={0,0,0};
	cin>>n;
	for(int i=1,u,v,w;i<=n;i++) cin>>u>>v>>w,a[i]={u,v,w},mxa=max(mxa,v),mxb=max(mxb,w);
    if(mxa==0&&mxb==0)
    {
        int rsum=0;
        sort(a+1,a+n+1,[](node x,node y){return x.x>y.x;});
        for(int i=1;i<=n/2;i++)
        {
            rsum+=a[i].x;
        }
        cout<<rsum<<endl;
        return ;
    }
    dfs(1);
	cout<<sum<<endl;
}

signed main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	fastread;
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}