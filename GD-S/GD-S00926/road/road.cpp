#include<bits/stdc++.h>
using namespace std;
bool flag=true;
struct lu{
	int start,end,m;
};
bool cmp(lu x,lu y){
	x.m<y.m;
}
int ans;
vector<lu> v;
int head[1000005];
int main(){
	int n,m,k;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		lu q;
		scanf("%d%d%d",&q.start ,&q.end ,&q.m );
	}
	for(int i=1;i<=k;i++){
		int c;
		for(int i=0;i<=n;i++){
			scanf("%d",&c);
			if(c!=0) flag=false;
		}
	}
	if(flag) printf("0");
	sort(v.begin(),v.end(),cmp);
	for(int i=1;i<=n;i++){
		head[i]=i;
	}
	for(int i=0;i<m;i++){
		if(head[v[i].start]!=head[v[i].end]){
			ans+=m;
			head[v[i].start]=head[v[i].end];
		}
	}
	printf("%d",ans);
}
