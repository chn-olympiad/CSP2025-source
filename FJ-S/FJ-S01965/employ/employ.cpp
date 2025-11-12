#include<iostream>
#include<algorithm>
using namespace std;
const int N=505,Mod=998244353;
int n,m;
int a[N],b[N],p[N],f[1<<18][20],popcnt[1<<18];
char s[N];

int add(int &x,int y){ return x=x+y>=Mod?x+y-Mod:x+y;}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=18){
		f[0][0]=1;
		for(int i=0;i<1<<n;i++){
			for(int j=0;j<n;j++){
				if(i>>j&1) popcnt[i]++;
			}
			b[i]=i;
		}
		sort(b,b+(1<<n),[=](int &x,int &y){ return popcnt[x]<popcnt[y];});
		for(int i=0;i<1<<n;i++){
			int x=b[i],t=popcnt[x]+1;
			for(int j=0;j<=popcnt[x];j++){
				if(!f[x][j]) continue;
				for(int k=0;k<n;k++){
					if(x>>k&1) continue;
					if(s[t]=='0'||j>=a[k+1]) add(f[x|(1<<k)][j+1],f[x][j]);
					else add(f[x|(1<<k)][j],f[x][j]);
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++) add(ans,f[(1<<n)-1][i]);
		printf("%d",ans);
		return 0;
	}
	return 0;
}
