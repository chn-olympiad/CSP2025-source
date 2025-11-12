#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N(1e5+5);
int T,n,cnt[4],ans;
struct node{
	int a[4];
	int mx,mn,md;
}d[N],m[N];
int l;
bool cmp(node a,node b){
	if(a.mx==b.mx){
		if(a.md==b.md)return a.mn>b.mn;
		return a.md>b.md; 
	}return a.mx>b.mx;
}
bool cmp1(node a,node b){
	return a.a[0]<b.a[0];
}
inline void solve(){
	scanf("%d",&n);l=0;ans=0;
	for(int i(1);i<=n;++i){
		for(int j(1);j<=3;++j){
			cnt[j]=0;
			scanf("%d",&d[i].a[j]);
		}
		d[i].mn=min({d[i].a[1],d[i].a[2],d[i].a[3]});
		d[i].mx=max({d[i].a[1],d[i].a[2],d[i].a[3]});
		d[i].md=d[i].a[1]+d[i].a[2]+d[i].a[3]-d[i].mn-d[i].mx;
	}sort(d+1,d+n+1,cmp);
	for(int i(1);i<=n;++i){
		if(d[i].mx==d[i].a[1])++cnt[1],ans+=d[i].a[1];
		else if(d[i].mx==d[i].a[2])++cnt[2],ans+=d[i].a[2];
		else if(d[i].mx==d[i].a[3])++cnt[3],ans+=d[i].a[3];
	}
	int dt(0);
	for(int i(1);i<=3;++i){
		if(cnt[i]>n/2){
			dt=i;
			for(int j(1);j<=n;++j){
				if(d[j].mx==d[j].a[i]){
					m[++l]=d[j];
					m[l].a[0]=m[l].mx-m[l].md;
				}
			}
			break;
		}
	}sort(m+1,m+l+1,cmp1);
	if(dt==0){
		printf("%d\n",ans);
		return ;
	}
	for(int i(1);i<=cnt[dt]-n/2;++i){
		ans-=m[i].mx;
		ans+=m[i].md;
	}printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
