#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 100005
using namespace std;
inline int max2(int a,int b){
	return a>b?a:b;
}
inline int max3(int a,int b,int c){
	return a>max(b,c)?a:max(b,c);
}
int a[MAXN],b[MAXN],c[MAXN],f[MAXN];
int g[MAXN];int gn;

int an,bn,cn;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	
	while(t--){
		int an=0,bn=0,cn=0;
		gn=0;
		int n;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
			f[i]=max3(a[i],b[i],c[i]);
			if(f[i]==a[i])an++;
			else if(f[i]==b[i])bn++;
			else cn++;
		}
		int wn;
		
		if(an>n/2){
			for(int i=1;i<=n;i++)
				if(f[i]==a[i])
					g[++gn]=a[i]-max2(b[i],c[i]);
			wn=an-n/2;
		}
		else if(bn>n/2){
			for(int i=1;i<=n;i++)
				if(f[i]==b[i])
					g[++gn]=b[i]-max2(a[i],c[i]);
			wn=bn-n/2;
		}
		else if(cn>n/2){
			for(int i=1;i<=n;i++)
				if(f[i]==c[i])
					g[++gn]=c[i]-max2(a[i],b[i]);
			wn=cn-n/2;
		}
		if(gn)sort(g+1,g+gn+1);
		
		
		int sum=0;
		for(int i=1;i<=n;i++)sum+=f[i];
		if(gn)for(int i=1;i<=wn;i++)sum-=g[i];
		printf("%d\n",sum);
	}
	return 0;
}
