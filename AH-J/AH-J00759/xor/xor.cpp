#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
vector<int> g[(1<<21)+5];
struct node{
	int l,r;
}b[N];
int a[N],s[N],tot;
bool cmp(node a,node b){
	if(a.r!=b.r) return a.r<b.r;
	return a.l>b.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		g[s[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int t=k^s[i-1];
		int l=lower_bound(g[t].begin(),g[t].end(),i)-g[t].begin();
		if(g[t].begin()+l<g[t].end()){
			b[++tot]={i,g[t][l]};
		}
	}
	sort(b+1,b+tot+1,cmp);
	int ans=0,nowr=0;
	for(int i=1;i<=tot;i++){
		if(b[i].l>nowr){
			ans++,nowr=b[i].r;
		}
	}
	cout<<ans<<endl;
	return 0;         
}
