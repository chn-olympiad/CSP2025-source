#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int val[3],id[3],dff;
	
	node(int v0=0,int v1=0,int v2=0){
		val[0]=v0;
		val[1]=v1;
		val[2]=v2;
		id[0]=0;
		id[1]=1;
		id[2]=2;
		sort(id,id+3,[&](int u,int v){
			return val[u]<val[v];
		});
		dff=val[id[2]]-val[id[1]];
	}
} a[N];
bool cmp(node a,node b){
	return a.dff>b.dff;
}
int n,cnt[3];
long long ans;
void test(){
	ans=0;
	cnt[0]=cnt[1]=cnt[2]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a0,a1,a2;
		cin>>a0>>a1>>a2;
		a[i]=node(a0,a1,a2);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(cnt[a[i].id[2]]<n/2){
			ans+=a[i].val[a[i].id[2]];
			cnt[a[i].id[2]]++;
		}else{
			ans+=a[i].val[a[i].id[1]];
			cnt[a[i].id[1]]++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t; cin>>t;
	while(t--) test();
	return 0;
}
