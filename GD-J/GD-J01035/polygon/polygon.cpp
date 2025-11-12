#include<cstdio>
#define pen putchar('\n')
#define pk putchar(' ')
inline int max(int x,int y) { return x>y?x:y; }
const int inf=-2147483647;
int n,ans=0,cnt=0,a[500001];
bool v[500001];
void dfs(int x,int s,int l,int d,int maxx) {
	if(s==d) {
		if(l>maxx*2) ans++;
		return ;
	}
	for(int j=x;j<=n;++j) 
		if(!v[j]) {
			v[j]=true;
			dfs(j,s+1,l+a[j],d,max(maxx,a[j]));
			v[j]=false;
		}
	return ; //好习惯 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int k=3;k<=n;++k) dfs(1,0,0,k,inf);
	printf("%d",ans);
	return 0;
} 
//补药骂我，我真的只会暴搜~
//愿RP++ 
