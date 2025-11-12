#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int ans=-1e9,a[maxn][5],n,cnt1,cnt2,cnt3,b[maxn];
struct awa{
	int l,r;
}c[maxn];
bool cmp1(awa a,awa b){
	if(a.l!=b.l)return a.l<b.l;
	return a.r<b.r;
}
bool cmp2(awa a,awa b){
	if(a.r!=b.r)return a.r<b.r;
	return a.l<b.l;
}
void dfs(int x,int i,int j,int l,int sum){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	if(i<n/2)dfs(x+1,i+1,j,l,sum+a[x][1]);
	if(j<n/2)dfs(x+1,i,j+1,l,sum+a[x][2]);
	if(l<n/2)dfs(x+1,i,j,l+1,sum+a[x][3]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]==0)cnt1++;
			if(a[i][2]==0)cnt2++;
			if(a[i][3]==0)cnt3++;
		}
		if(cnt1==n&&cnt2==n||cnt1==n&&cnt3==n||cnt3==n&&cnt2==n){
			if(cnt1==n)for(int i=1;i<=n;i++)c[i].l=a[i][2],c[i].r=a[i][3];
			if(cnt2==n)for(int i=1;i<=n;i++)c[i].l=a[i][1],c[i].r=a[i][3];
			if(cnt3==n)for(int i=1;i<=n;i++)c[i].l=a[i][1],c[i].r=a[i][2];
			sort(c+1,c+1+n,cmp1);
			int sum1=0,sum2=0;
			for(int i=1;i<=n/2;i++)sum1+=c[i].l,sum2+=c[i].r;
			for(int i=n/2+1;i<=n;i++)sum2+=c[i].l,sum1+=c[i].r;
			ans=max(sum1,sum2);
			sort(c+1,c+1+n,cmp2);
			sum1=0,sum2=0;
			for(int i=1;i<=n/2;i++)sum1+=c[i].l,sum2+=c[i].r;
			for(int i=n/2+1;i<=n;i++)sum2+=c[i].l,sum1+=c[i].r;
			ans=max(sum1,sum2);
			cout<<ans<<"\n";
		}
		else{
			ans=-1e9;
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
		}
	}
}
