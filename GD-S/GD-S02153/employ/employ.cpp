//f_{i,j,S} 表示前 i 天，录用了 j 个人，面试人的集合为 S
#include<bits/stdc++.h>
#define lowbit(S) ((S)&(-(S)))
#define bit(S,i) (((S)>>(i))&1)
using namespace std;
bool st;
const int N=20,MO=998244353;
int n,m,ans,c[N],popc[1<<18],f[2][N][1<<18];
char s[N];
basic_string<int> v[N];
void add(int &x,int y){
	x+=y;
	if(x>=MO) x-=MO;
}
bool ed;
int main(){
//	cout<<((&st)-(&ed))/1024/1024<<endl;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	popc[0]=0;
	for(int S=1;S<(1<<n);S++) popc[S]=popc[S-lowbit(S)]+1;
	for(int S=0;S<(1<<n);S++) v[popc[S]].push_back(S);
	f[0][0][0]=1;
	for(int i=0;i<n;i++){
		memset(f[i+1&1],0,sizeof(f[i+1&1]));
		for(int j=0;j<=i;j++){
			for(auto S:v[i]){
//				printf("%d %d %d->%d %c\n",i,j,S,f[i][j][S],s[i+1]); 
				for(int k=1;k<=n;k++){
					if(bit(S,k-1)) continue;
					if(s[i+1]=='0'||i-j>=c[k]) add(f[i+1&1][j][S|(1<<(k-1))],f[i&1][j][S]);
					else add(f[i+1&1][j+1][S|(1<<(k-1))],f[i&1][j][S]); 
				}
			}
		}
	}
	for(int i=m;i<=n;i++){
		add(ans,f[n&1][i][(1<<n)-1]);
	}
	printf("%d\n",ans);
	return 0;
}
