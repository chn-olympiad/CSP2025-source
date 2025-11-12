#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5;
struct node{int d,a,b,c;}a[maxn];
int t,n,cnt[5],ans;
bool cmp(node a,node b){return a.d>b.d;}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c); 
			int x=a[i].a,y=a[i].b,z=a[i].c;
			if(x>y) swap(x,y);
			if(y>z) swap(y,z);
			if(x>y) swap(x,y);
			a[i].d=z-y;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			int x=a[i].a,y=a[i].b,z=a[i].c,id1,id2;
			if(x>y) swap(x,y);
			if(y>z) swap(y,z);
			if(x>y) swap(x,y);
			if(z==a[i].a) id1=1;
			if(z==a[i].b) id1=2;
			if(z==a[i].c) id1=3;
			if(y==a[i].c) id2=3;
			if(y==a[i].b) id2=2;
			if(y==a[i].a) id2=1;
			if(cnt[id1]<n/2){
				cnt[id1]++;
				ans+=z;
			}
			else cnt[id2]++,ans+=y;
		}
		cout<<ans<<endl;
	}
}

