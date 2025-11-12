#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> PII;
const int N=5e5+10;
unordered_map<int,int> m;
int n,k,sumxor[N],pos,ans;
vector<PII> g;
bool cmp(PII x,PII y){
	if(x.s!=y.s) return x.s<y.s;
	return x.f>y.f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&sumxor[i]);
		sumxor[i]^=sumxor[i-1];
		if(m[k^sumxor[i]] || k==sumxor[i]) g.push_back({m[k^sumxor[i]],i});
		m[sumxor[i]]=i;
	}
	sort(g.begin(),g.end(),cmp);
	for(size_t i=0;i<g.size();++i){
		if(g[i].f>=pos){
			++ans;
			pos=g[i].s;
		}
	}
	printf("%d",ans);
	return 0;
}
