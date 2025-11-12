#include<bits/stdc++.h>

using namespace std;

const int N=3e5+10;
int t;
int n;
int cnt[5];
bool vis[N],tot;
struct node{
	int a,b,c;
}d[N];
struct node2{
	int w,id,x;
}a[N];
bool cmp(node x,node y){
	return x.a>y.a;
}
bool cmp2(node2 x,node2 y){
	return x.w>y.w;
}
int ans=-1;
int k;
void dfs(int x,int a,int b,int c,int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(a+1<=k){
		dfs(x+1,a+1,b,c,sum+d[x].a)	;
	}
	if(b+1<=k){
		dfs(x+1,a,b+1,c,sum+d[x].b)	;
	}
	if(c+1<=k)
		dfs(x+1,a,b,c+1,sum+d[x].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	
	while(t--){
		ans=0;
		scanf("%d",&n);
		bool flag=true;
		tot=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);
			a[++tot]={d[i].a,i,1};//w id x
			a[++tot]={d[i].b,i,2};
			a[++tot]={d[i].c,i,3};
			if(!(d[i].b==d[i].c && d[i].b==0))
				flag=false;
		}
			
		k=n/2;	
		if(n<=10){
			dfs(1,0,0,0,0);
			printf("%d\n",ans);	
		}	
		else if(flag){
			sort(d+1,d+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=d[i].a;
			printf("%d\n",ans);
		}
		else{
			memset(vis,0,sizeof(0));
			memset(cnt,0,sizeof(0));
			sort(a+1,a+tot+1,cmp2);
			int sum=0;
			for(int i=1;i<=tot;i++){
				if(!vis[a[i].id] && cnt[a[i].x]<k)
				{	
					//cout<<a[i].w<<" "<<a[i].id<<" "<<a[i].x<<endl;
					sum+=a[i].w;
					vis[a[i].id]=1;
					cnt[a[i].x]++;
				}
			}
			printf("%d\n",sum);
		}
	}



	fclose(stdin);
	fclose(stdout);
	return 0;
}

