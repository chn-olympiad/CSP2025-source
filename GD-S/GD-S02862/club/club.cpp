#include<bits/stdc++.h>
#define N 100005
using namespace std;
long long t,n,ans,m[4],p;
struct node{
	int w;
	int index;
}g[N][4];
struct node2{
	int l;
	int id;
}lost[N];
bool cmp(node x,node y){
	return x.w>y.w;
}
bool cmp2(node2 x,node2 y){
	return x.l<y.l;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0){
		t--;
		cin>>n;
		ans=0,p=0;
		m[1]=0;m[2]=0;m[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&g[i][1].w);
			scanf("%d",&g[i][2].w);
			scanf("%d",&g[i][3].w);
			g[i][1].index=1;
			g[i][2].index=2;
			g[i][3].index=3;
			sort(g[i]+1,g[i]+4,cmp);
			ans+=g[i][1].w;
			lost[i].l=g[i][1].w-g[i][2].w;
			lost[i].id=g[i][1].index;
			m[g[i][1].index]++;
		}
		if(m[1]>(n/2))p=1;
		else if(m[2]>(n/2))p=2;
		else if(m[3]>(n/2))p=3;
		if(p==0)cout<<ans<<"\n";
		else{
			sort(lost+1,lost+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(m[p]==(n/2))break;
				if(lost[i].id!=p)continue;
				ans-=lost[i].l;
				m[p]--;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
