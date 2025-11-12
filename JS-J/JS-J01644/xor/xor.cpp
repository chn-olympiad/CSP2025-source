#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls p<<1
#define rs p<<1|1
const int N=2e6+10;
int a[N];
int xxor[N];
void pushup(int p)
{
    xxor[p]=xxor[ls]^xxor[rs];
}
void build(int l,int r,int p)
{
    if(l==r)
    {
        xxor[p]=a[l];
        return ;
    }
    else
    {
        int mid=(l+r)>>1;
        build(l,mid,ls);
        build(mid+1,r,rs);
        pushup(p);
    }
}

int query(int jobl,int jobr,int l,int r,int p)
{
    if (jobl<=l&&r<=jobr)
    {
        return xxor[p];
    }
    else
    {
        int mid=(l+r)>>1;
        int ans=0;
        if (jobl<=mid)
        {
            ans^=query(jobl,jobr,l,mid,ls);
        }
        if (jobr>mid)
        {
            ans^=query(jobl,jobr,mid+1,r,rs);
        }
        return ans;
    }
}
int n,k,ans;
void dfs(int u,int last,int cnt){
	if (u==n+1){
		ans=max(ans,cnt);
		return ;
	}
	dfs(u+1,last,cnt);
	if (query(last,u,1,n,1)==k){
		dfs(u+1,u+1,cnt+1);
	}
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1; i<=n; i++) cin>>a[i];
    build(1,n,1);
    if (n<=20){
		dfs(1,1,0);
		cout<<ans<<endl;
	}else{
		if (k==0){
			int cnt0=0,cnt1=0;
			for (int i=1;i<=n;i++){
				if (a[i]==0){
					cnt0++;
				}
				if (a[i]==1){
					cnt1++;
				}
			}
			cout<<cnt0+cnt1/2<<endl;
		}else if (k==1){
			int cnt1=0;
			for (int i=1;i<=n;i++){
				if (a[i]==1){
					cnt1++;
				}
			}
			cout<<cnt1<<endl;
		}
    }
    return 0;
}
