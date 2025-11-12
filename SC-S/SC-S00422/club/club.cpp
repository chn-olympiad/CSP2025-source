#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[3][100100],f[210][210][210];
struct Node{
	int a,b,c;
}x[100100];
bool cmp(Node a,Node b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(f,-0x3f,sizeof(f));
		scanf("%d",&n);
		bool h=1;
		for(int i=1;i <= n;i++){
			scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
			if(a[1][i]!=0||a[2][i]!=0) h=0;
			x[i]={a[0][i],a[1][i],a[2][i]};
		}
		if(h){
			sort(a[0]+1,a[0]+n+1,greater<int>());
			int ans=0;
			for(int i=1;i <= (n>>1);i++){
				ans+=a[0][i];
			}
			cout<<ans<<"\n";
		}else if(n<=200){
			f[0][0][0]=0;
			for(int i=1;i <= n;i++){
				for(int j=0;j <= (n>>1);j++){
					for(int k=0;k <= (n>>1)&&j+k<=i;k++){
						f[i][j][k]=f[i-1][j][k]+a[2][i];
						if(j){
							f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[0][i]);
						}
						if(k){
							f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[1][i]);
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i <= (n>>1);i++){
				for(int j=1;j <= (n>>1);j++){
					int k=n-i-j;
					if(k>(n>>1)) continue;
					ans=max(ans,f[n][i][j]);
				}
			}
			cout<<ans<<"\n";
		}else{
			sort(x+1,x+n+1,cmp);
			int ans=0;
			for(int i=1;i <= (n>>1);i++){
				ans+=x[i].a;
			}
			int p1=0,p2=0;
			for(int i=(n>>1)+1;i <= n;i++){
				if(x[i].b>=x[i].c&&p1<(n>>1)||p2==(n>>1)){
					ans+=x[i].b;
					p1++;
				}else{
					ans+=x[i].c;
					p2++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
