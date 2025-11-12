#include<bits/stdc++.h>
#define mx(a,b,c) max(a,max(b,c))
typedef long long ll;
using namespace std;
const int N = 5e5+5;
ll a[N],b[N],w[N],k;
int dp[N],n,cnt,m,ans;
map<ll,int>mp;
struct node{
	int l,r;
}c[N];
bool cmp(node a,node b){
	return a.l<b.l;
}
int middle(int x){
	int l=0,r=cnt+1,mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(c[mid].l>x)r=mid;
		else l=mid;
	};
	return r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=b[i-1]^a[i];
		mp[b[i]]=i+1;
		if(a[i]==k){
			c[++cnt]=node{i,i};
			//printf("5431:%d %d\n",i,i);
		}
		else if(flag&&b[i]==k){
			flag=0;
			c[++cnt]=node{1,i};
			//printf("5432:%d %d\n",1,i);
		}
		else{
			//printf("??:%lld %d\n",b[i],i);
			int &p=mp[b[i]^k];
			if(p!=0&&p<i){
				c[++cnt]=node{p,i};
				//printf("5433:%d %d\n",p,i);
				p=0;
			}
		}
	}
	//printf("cnt:%d\n",cnt);
	//printf("%lld %lld %d\n",b[1],b[4],mp[2]);
	//for(int i=1;i<=cnt;i++)printf("%d %d\n",c[i].l,c[i].r);
	c[++cnt]=node{n+1,n+1};
	sort(c+1,c+1+cnt,cmp);
	for(int i=1;i<cnt;i++){
		dp[i]=mx(dp[i],1,dp[i-1]);
		m=middle(c[i].r);
		dp[m]=max(dp[m],dp[i]+1);
	}
	dp[cnt]--;
	for(int i=1;i<=cnt;i++)ans=max(ans,dp[i]);
	cout<<ans;
    return 0;
}
