#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=300;
struct node{
	int a,b,c;
}a2[N];
int n,f[N][10][N],T,a[N][10],b[10][(1<<17)],dp[10][(1<<17)];
map<int,int>vis;
bool check2(){
	for(int i=1;i<=n;i++){
		if(a[i][2]!=0||a[i][3]!=0)return 0;
	}
	return 1;
}
bool cmp(node a,node b){
	return a.a>b.a;
}
bool check(int t){
	int k2=t,k3=0;
	while(k2){
		k3+=k2%2;
		k2/=2;
	}
	if(k3<=(n>>1))return 1;
	else return 0;
}
int tp(int t,int x){
	int k2=t,res=0;
	int g=0;
	while(k2){
		g++;
		res+=a[g*(k2%2)][x];
		k2/=2;
	}
	return res;
}
bool tcheck(int x,int y){
	int t1=b[1][x],t2=b[1][y];
	int g=max(t1,t2);
	while(g){
		if(t1%2==t2%2)return 0;
		t1/=2;
		t2/=2;
		g/=2;
	}
	return 1;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		if(a[1][1]+a[1][3]==0){
			for(int i=1;i<=n;i++){
				swap(a[i][1],a[i][2]);
			}
		}
		if(a[1][1]+a[1][2]==0){
			for(int i=1;i<=n;i++){
				swap(a[i][1],a[i][3]);
			}
		}
		if(check2()){
			int ans=0;
			for(int i=1;i<=n;i++){
				a2[i].a=a[i][1],a2[i].b=a[i][2],a2[i].c=a[i][3];
			}
			sort(a2+1,a2+1+n,cmp);
			for(int i=1;i<=(n>>1);i++){
				ans+=a2[i].a;
			}
			printf("%d\n",ans);
			continue;
		}
		if(n<=4){
			int t=0,n1=0,ans=0;
			int g=(1<<(n));
			for(int i=1;i<=g;i++){
				if(t>=g)break;
				if(check(t)){
					b[1][++n1]=t;
					b[2][n1]=t;
					b[3][n1]=t;
					dp[1][n1]=tp(t,1);
					dp[2][n1]=tp(t,2);
					dp[3][n1]=tp(t,3);
//					cout<<t<<" "<<dp[1][n1]<<endl;
				}
				t++;
			}
			for(int i=1;i<=n1;i++){
				for(int j=1;j<=n1;j++){
					if(i==j)continue;
					if(!tcheck(i,j)){
						continue;
					}
					if(b[1][i]+b[2][j]<g){
						ans=max(ans,dp[1][i]+dp[2][j]+tp(g-1-b[1][i]-b[2][j],3));
					}
					if(b[1][i]+b[3][j]<g){
						ans=max(ans,dp[1][i]+dp[3][j]+tp(g-1-b[1][i]-b[3][j],2));
					}
					if(b[2][i]+b[3][j]<g){
						ans=max(ans,dp[2][i]+dp[3][j]+tp(g-1-b[2][i]-b[3][j],1));
					}
				}
			}
//			cout<<dp[1][]
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=(n>>1);k++){
					for(int j2=1;j2<=3;j2++){
						if(j!=j2){
							for(int k2=1;k2<=(n>>1);k2++){
								f[i][j][k]=max(f[i][j][k],f[i-1][j2][k2]+a[i][j]);
							}
							f[i][j][k]=max(f[i][j][k],a[i][j]);
						}else{
							if(k>1){
								f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][j]);
							}else{
								f[i][j][k]=max(f[i][j][k],a[i][j]);
							}
						}
					}
				}
			}
		}
		int ans=0;
		for(int j=1;j<=3;j++){
			for(int k=1;k<=(n>>1);k++){
				ans=max(ans,f[n][j][k]);
//				cout<<f[n][j][k]<<' ';
			}
//			cout<<endl;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
