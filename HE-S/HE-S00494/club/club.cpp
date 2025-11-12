#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int t;

int n;

int cnt[5];
struct point{
	int w,j;
};
struct node{
	point a[5];
}e[N];

bool cmp1(point x,point y){
	return x.w>y.w;
}

bool cmp2(node x,node y){
	int i=1;
	while(x.a[i].w==y.a[i].w&&i<=3) i++;
	return x.a[i].w>y.a[i].w;
}

void solve(){
	for(int i=0;i<5;i++) cnt[i]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>e[i].a[j].w;
			e[i].a[j].j=j;
		}
		sort(e[i].a+1,e[i].a+1+3,cmp1);
	}
	sort(e+1,e+1+n,cmp2);
	int k=n/2;
	int ans=0;
	for(int i=1;i<=n;i++){
		int u=1;
		int j=e[i].a[u].j;
		while(cnt[j]>=k) j=e[i].a[++u].j;
		cnt[j]++;
		ans+=e[i].a[u].w;
	}
	cout<<ans<<endl;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
