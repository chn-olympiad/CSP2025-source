#include<cstdio>
#include<cstring>
int T,n,p1[100500],p2[100500],p3[100500];
struct ps{
	int a1,a2,a3;
}ar[100500];
int df[250][250][250];
inline int max(int a,int b){return a>b?a:b;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&ar[i].a1,&ar[i].a2,&ar[i].a3);
		int ans=0;
		if(n<249)
		for(int i=0;i<=n/2;i++)
			for(int j=0;j<=n/2;j++)
				for(int k=0;k<=n/2&&i+j+k<=n;k++){
					if(i<n/2)df[i+1][j][k]=max(df[i][j][k]+ar[i+j+k].a1,df[i+1][j][k]);
					if(j<n/2)df[i][j+1][k]=max(df[i][j][k]+ar[i+j+k].a2,df[i][j+1][k]);
					if(k<n/2)df[i][j][k+1]=max(df[i][j][k]+ar[i+j+k].a3,df[i][j][k+1]);
					ans=max(max(df[i+1][j][k],ans),max(df[i][j+1][k],df[i][j][k+1]));
				}
		printf("%d\n",ans);
		memset(df,0,sizeof df);
	}
	return 0;
} 
