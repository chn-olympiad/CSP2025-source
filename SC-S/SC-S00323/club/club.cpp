#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt1,cnt2,cnt3,ans;
struct people{
	int a1,a2,a3;
}a[100005],b[100005],c[100005];
bool cmp(people a,people b){
	return a.a1-a.a2<b.a1-b.a2;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		int x,y,z;
		scanf("%ld%ld%ld",&x,&y,&z);
		int x1=max(max(x,y),z),y1,z1=min(min(x,y),z);
		y1=x+y+z-x1-z1;
		ans+=x1;
		if(x==x1){
			a[++cnt1].a1=x1;
			a[cnt1].a2=y1;
			a[cnt1].a3=z1;
		}else if(y==x1){
			b[++cnt2].a1=x1;
			b[cnt2].a2=y1;
			b[cnt2].a3=z1;
		}else if(z==x1){
			c[++cnt3].a1=x1;
			c[cnt3].a2=y1;
			c[cnt3].a3=z1;
		}
	}
	sort(a+1,a+1+cnt1,cmp);
	sort(b+1,b+1+cnt2,cmp);
	sort(c+1,c+1+cnt3,cmp);
	int ex1=max(max(cnt1,cnt2),cnt3)-n/2;
	if(cnt1>n/2){
		for(int i=1;i<=ex1;++i){
			ans=(ans-a[i].a1+a[i].a2);
		}
	}else if(cnt2>n/2){
		for(int i=1;i<=ex1;++i){
			ans=(ans-b[i].a1+b[i].a2);
		}
	}else if(cnt3>n/2){
		for(int i=1;i<=ex1;++i){
			ans=(ans-c[i].a1+c[i].a2);
		}
	}
	printf("%ld\n",ans);
	cnt1=cnt2=cnt3=ans=0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(++t;--t;){
		solve();
	} 
	return 0;
}
