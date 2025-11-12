#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
const int maxn=200+10;
int n,t;
ll val[100010][5],f[maxn][maxn][maxn],ans;
void mian(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			scanf("%lld",&val[i][j]); 
		} 
	}
	ans=0;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int s1=0;s1<=i;s1++)
			for(int s2=0;s2<=i-s1;s2++){
				int s3=i-s1-s2;
				if(s3<0)
					continue;
				if(s1>=1)
					f[i][s1][s2]=max(f[i][s1][s2],f[i-1][s1-1][s2]+val[i][1]);
				if(s2>=1)
					f[i][s1][s2]=max(f[i][s1][s2],f[i-1][s1][s2-1]+val[i][2]);
				if(s3>=1)
					f[i][s1][s2]=max(f[i][s1][s2],f[i-1][s1][s2]+val[i][3]);
				if(i==n&&s1<=n/2&&s2<=n/2&&s3<=n/2){
					ans=max(ans,f[i][s1][s2]);
				} 
			} 
	}
	printf("%lld\n",ans);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		mian();
	}
	return 0; 
}
