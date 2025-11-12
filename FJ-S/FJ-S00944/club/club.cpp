#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+3;
struct edge{
	int from,to,weight;
}e[MAXN*3];
bool cmp(edge a,edge b){
	return a.weight>b.weight;
}
vector<bool> chose;
int be_chose[4];
long long ans=0,cnt;
void fun(int m,int n){
	ans=0,cnt=0;
	for(int i=1;i<=3;i++){
		be_chose[i]=0;
	}
	for(int i=1;i<=m;i++){
		if(be_chose[e[i].from]>=n/2) continue;
		if(chose[e[i].to]) continue;
		ans+=e[i].weight;
		cnt++;
		chose[e[i].to]=true;
		be_chose[e[i].from]++;
		if(cnt==n) return ;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t,temp;
	cin>>t;
	int n,m=0;
	while(t--){
		if(temp-1!=t&&t!=1){
			for(int i=1;i<=m;i++){
				e[i].from=0,e[i].to=0,e[i].weight=0;
			}
		}
		m=0;
		cin>>n;
		chose.assign(n+1+3,false);
		for(int i=1,a,b,c;i<=n;i++){
			cin>>a>>b>>c;
			e[++m].from=1;
			e[m].to=i+3;
			e[m].weight=a;
			e[++m].from=2;
			e[m].to=i+3;
			e[m].weight=b;
			e[++m].from=3;
			e[m].to=i+3;
			e[m].weight=c;
		}
		sort(e+1,e+1+m,cmp);
		fun(m,n);
		cout<<ans<<endl;
	}
	return 0;
}
