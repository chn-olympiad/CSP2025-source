#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,cl[5][N],f;
long long ans;

struct node{
	int x,id;
};

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		ans=f=0;
		memset(cl,0,sizeof(cl));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			node a,b,c;
			scanf("%d%d%d",&a.x,&b.x,&c.x);
			a.id=1,b.id=2,c.id=3;
			if(a.x<b.x) swap(a,b);
			if(c.x>a.x) swap(a,b),swap(a,c);
			else if(c.x>b.x) swap(b,c);
			cl[a.id][++cl[a.id][0]]=a.x-b.x;
			ans+=a.x;
			if(f==0&&cl[a.id][0]>n/2) f=a.id;
		}
		if(f!=0){
			sort(cl[f]+1,cl[f]+1+cl[f][0]);
			int k=cl[f][0]-(n/2);
			for(int i=1;i<=k;i++) ans-=cl[f][i];
		}
		printf("%lld\n",ans);
	}
	
	
} 
