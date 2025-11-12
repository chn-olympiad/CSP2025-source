#include<bits/stdc++.h>
#define int long long
using namespace std;

struct mynode{
	int from,to,len,tag;
	bool operator < (const mynode &cnt) const{
		return len>cnt.len;
	}
};

const int N=1e4+5;
int n,m,k,fa[N],ans,cun[N],cunlen[N];
bool flag[N];
priority_queue<mynode> edge;
mynode res;

int getf(int num){
	if(fa[num]==num){
		return num;
	}
	else{
		int cnt=getf(fa[num]);
		fa[num]=cnt;
		return cnt;
	}
}

void mymerge(int f,int s){
	fa[s]=f;
}

void func(){
	int cnt=0;
	while(!edge.empty()){
		res=edge.top();
		edge.pop();
		int f1=getf(res.from);
		int f2=getf(res.to);
		if(f1!=f2){
			mymerge(res.from,res.to);
			cnt++;
			ans+=res.len;
			if(res.tag!=0&&flag[res.tag]==true){
				ans--;
			}
			if(res.tag!=0){
				flag[res.tag]=true;
			}
		}
		if(cnt==n-1) break;
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&res.from,&res.to,&res.len);
		if(res.from>res.to){
			swap(res.from,res.to);
		}
		res.tag=0;
		edge.push(res);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&cun[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&cunlen[j]);
		}
		for(int fro=1;fro<n;fro++){
			for(int t=fro+1;t<=n;t++){
				res.from=fro;
				res.to=t;
				res.len=cun[i]+cunlen[res.from]+cunlen[res.to];
				res.tag=i;
				edge.push(res);
			}
		}
	}
	func();
	printf("%lld",ans);
	return 0;
}