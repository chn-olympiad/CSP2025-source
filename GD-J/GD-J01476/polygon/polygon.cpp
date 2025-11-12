#include<bits/stdc++.h>

typedef int IT;
typedef long long LL;
typedef __int128 int128;
typedef double DB;

#define pb push_back
#define fst first
#define sec second
#define psh push
#define PII pair<IT,IT>
#define PLI pair<LL,IT>
#define lowbit(x) ((x)&(-x))

using namespace std;

const int N=2e1+10;
const LL P=998244353;

//void qread(auto &sum){
//    sum=0;
//    auto f=sum+1;
//    char ch=getchar();
//    while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
//    while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-48;ch=getchar();}
//    sum*=f;
//    return;
//}
//
//void qp(auto x){
//    if(x>9) qp(x/10);
//    putchar(x%10+48);
//    return;
//}
//void qpp(auto x){
//    if(x<0) x=-x,putchar('-');
//    qp(x);
//    return;
//}

int n;
int a[N];

bool c[N];
LL ans;
vector<int>g;
void work(){
	g.clear();
	for(int i=1;i<=n;i++){
		if(c[i]) g.pb(a[i]);
	}
	
	int mx=0,sum=0;
	for(int i=0,lg=g.size();i<lg;i++) mx=max(mx,g[i]),sum+=g[i];
	
	if(sum>mx*2) ans++;
	
	return;
}
void dfs(int x){
	if(x>n){
		work();
		return;
	}
	c[x]=1;
	dfs(x+1);
	c[x]=0;
	
	dfs(x+1);
	return;
}

int main(){
    freopen("polygon.in","r",stdin);
//    freopen("polygon3.in","r",stdin);
    freopen("polygon.out","w",stdout);

	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	dfs(1);
	
	printf("%lld\n",ans);
    return 0;
}
