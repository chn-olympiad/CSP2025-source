#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
inline int read();
const int N = 1e5 + 10;
struct node{
	int max1,bel1;
	int max2,bel2;
	int cha;
}a[N];
bool cmp(node x,node y){
	return x.cha > y.cha;
}
int lim[N];
void solve(){
	memset(lim,0,sizeof lim);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i].max1=0;a[i].max2=0;
		for(int j=1;j<=3;j++){
			int aa=read();
			if(a[i].max1 <= aa){
				a[i].max2 = a[i].max1;
				a[i].bel2=a[i].bel1;
				a[i].max1 = aa;
				a[i].bel1=j;
			}
			else{
				if(aa > a[i].max2){
					a[i].max2 = aa;
					a[i].bel2 = j;
				}
			}
		}
		a[i].cha = a[i].max1 - a[i].max2;
	}
	sort(a+1,a+1+n,cmp);
	LL ans = 0;
	for(int i=1;i<=n;i++){
		if(lim[a[i].bel1] < n/2){
			ans+=a[i].max1;
			lim[a[i].bel1]++;
		}
		else{
			ans+=a[i].max2;
			lim[a[i].bel2]++;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t = read();
	while(t--){
		solve();
	}
	return 0;
}
inline int read(){
	char x=getchar();
	int res = 0;
	int f = 1;
	while(x < '0' || x >'9'){
		if(x == '-') f =-1;
		x = getchar();
	}
	while(x >='0' && x <='9'){
		res = res * 10 + (x -'0');
		x=getchar();
	}
	return res * f;
}

