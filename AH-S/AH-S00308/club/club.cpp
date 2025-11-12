#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
const int MN=1e5+5;
typedef struct S{
	int num,id,p;
	bool operator <(const S &rhs)const{
		return num<rhs.num;
	}
}S;
int T,n;
priority_queue<S> a;//num id
bool vis[MN];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int a1,a2,a3;
		if(!a.empty())a.pop();
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a1,&a2,&a3);
			a.push(S{a1,i,1});
			a.push(S{a2,i,2});
			a.push(S{a3,i,3});
		}
		//puts("A");
		memset(vis,0,sizeof(vis));
		int u=0,ans=0,l[4]={0,0,0,0};
		while(u<n){
			//puts("C");
			S t=a.top();
			a.pop();
			//cout<<t.id<<" "<<a.size()<<" "<<u<<endl;
			if(vis[t.id])continue;
			if(l[t.p]+1>n/2)continue;
			vis[t.id]=true;
			++l[t.p];
			ans+=t.num;
			++u;
			//puts("F");
			//printf("%d %d %d ",u,ans,t.num);
			//cout<<a.size()<<endl;
		}
		//puts("B");
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
