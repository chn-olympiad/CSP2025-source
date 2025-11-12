#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,mod=998244353;
int n,m,f[2][N][N],cnt[N],sum[N],c[N][N],jc[N];
char s[N];
void add(int &x,int y){
	((x+=y)>=mod)&&(x-=mod);
}
int __mod(int x){
	return x>=mod?x-mod:x;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	c[0][0]=1;jc[0]=1;
	for(int i=1;i<=n;i++){
		c[i][0]=1;jc[i]=(ll)jc[i-1]*i%mod;
		for(int j=1;j<=i;j++){
			c[i][j]=__mod(c[i-1][j-1]+c[i-1][j]);
		}
	}
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);cnt[x]++;
	}
	for(int i=n;i>=0;i--)sum[i]=sum[i+1]+cnt[i];
	f[0][0][n-cnt[0]]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i+1;j++){
			for(int k=0;k<=min(n-i-1,sum[j+1]);k++){
				f[i+1&1][j][k]=0;
			}
		}
		for(int j=0;j<=i;j++){
			for(int k=0;k<=min(n-i,sum[j+1]);k++){
				if(!f[i&1][j][k])continue;
				if(i<n){
					int w=f[i&1][j][k];
					if(s[i+1]=='0'){
						int x=sum[j+1]-k;
						for(int y=0;y<=min(x,cnt[j+1]);y++){
							if(k-(cnt[j+1]-y)<0){
								continue;
							}
							int xi=(ll)c[x][y]*c[cnt[j+1]][y]%mod*jc[y]%mod;
							add(f[i+1&1][j+1][k-(cnt[j+1]-y)],(ll)w*xi%mod*(n-i-k)%mod);//<=j
							if(y<cnt[j+1])add(f[i+1&1][j+1][k-(cnt[j+1]-y)],(ll)w*xi%mod*(cnt[j+1]-y)%mod);//j+1
							if(k-(cnt[j+1]-y)-1>=0){
								add(f[i+1&1][j+1][k-(cnt[j+1]-y)-1],(ll)w*xi%mod);//>j+1
							}
						}
					}
					else{
						if(k>0)add(f[i+1&1][j][k-1],w);
						int x=sum[j+1]-k;
						//<=j
						for(int y=0;y<=min(x,cnt[j+1]);y++){
							if(k-(cnt[j+1]-y)<0){
								continue;
							}
							add(f[i+1&1][j+1][k-(cnt[j+1]-y)],(ll)w*c[x][y]%mod*jc[y]%mod*c[cnt[j+1]][y]%mod*(n-i-k)%mod);
						}
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++){
		int sur=sum[i+1];
		int w=f[n&1][i][0];
		for(int j=i+1;j<=n;j++){
			w=(ll)w*c[sur][cnt[j]]%mod*jc[cnt[j]]%mod;
			sur-=cnt[j];
		}
		add(ans,w);
	}
	printf("%d",ans);
	return 0;
}
