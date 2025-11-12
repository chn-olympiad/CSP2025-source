#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

struct node{
	int w,cnt[4];
}f[N][4];

int T,n,ans; 	//测试组数 人数 
int a[N][4];
int b[N];

bool flagA=1;

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);//测试组数 
	while(T--){
		//清空数据 
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		
		//输入 
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0||a[i][3]!=0)flagA=0;
		}
		//处理 
		
		if(flagA){//A
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+n+1,cmp);
			int res=0;
			for(int i=1;i<=n/2;i++){
				res+=b[i];
			}
			printf("%d",res);
			continue;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=3;j>=1;j--){
				for(int k=3;k>=1;k--){
					if(f[i-1][j].cnt[k]<n/2){
						if(f[i][k].w<f[i-1][j].w+a[i][k]){
							f[i][k].w=f[i-1][j].w+a[i][k];
						}
						f[i][k].cnt[k]=f[i-1][j].cnt[k]+1;
					}
				}
			}
		}
		//答案 
		printf("%d\n",max({f[n][1].w,f[n][2].w,f[n][3].w}));
	}
	return 0;
}
