#include<bits/stdc++.h>
using namespace std;
#define int long long
int in(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		k*=10;
		k+=c-'0';
		c=getchar();
	}
	return k*f;
}

const int N=1e4+7,M=1e6+7;

struct node{
	int u,v,val,cs;
}a[M*10];

int fa[N],cnt[N];
int n,m,k,ans;
int c[20],c_s[20][N];
bool f[20];

bool cmp(node x,node y){
	int xx=x.val;
	int yy=y.val;
	if(x.cs){
		if(!f[x.cs]){
			xx+=c[x.cs];
		}
	}
	if(y.cs){
		if(!f[y.cs]){
			yy+=c[y.cs];
		}
	}
	return xx<yy;
}

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

void merge(int x,int y,int w,int cs){
	x=find(x),y=find(y);
	if(x==y)return ;
	ans+=w;
	if(cs){
		if(!f[cs]){
			f[cs]=1;
			ans+=c[cs];
			sort(a+1,a+1+m,cmp);
		}
	}
	fa[x]=y;
	return ;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	
	for(int i=1;i<=m;i++){
		a[i].u=in();
		a[i].v=in();
		a[i].val=in();
		a[i].cs=0;
	}
	for(int i=1;i<=k;i++){
		c[i]=in();
		for(int j=1;j<=n;j++){
			c_s[i][j]=in();
		}
	}
	for(int g=1;g<=k;g++){
	    for(int i=1;i<=n;i++){
	    	for(int j=i+1;j<=n;j++){
	    		m++;
	    		a[m].u=i;
	    		a[m].v=j;
	    		a[m].val=c_s[g][i]+c_s[g][j];
	    		a[m].cs=g;
			}
		}
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		merge(a[i].u,a[i].v,a[i].val,a[i].cs);
	}
	cout<<ans;
	return 0;
} 
