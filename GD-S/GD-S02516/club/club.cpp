#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define in(s1) freopen(s1,"r",stdin);
#define out(s1) freopen(s1,"w",stdout);
#define pii pair<int,int>
template<typename T>
inline void read(T &x){
	x=0;
	char c=getchar();
	int f=1;
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+(c-'0');
		c=getchar();
	}
	x*=f;
}
template<typename T>
inline void write(T x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int N=1e5+10;
int T,n;
struct node{
	int a,b,c;
}x[N];
int ans;
void dfs(int idd,int s1,int s2,int s3,int sum){
	if(idd>n){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&s1+1<=n/2)dfs(idd+1,s1+1,s2,s3,sum+x[idd].a);
		if(i==2&&s2+1<=n/2)dfs(idd+1,s1,s2+1,s3,sum+x[idd].b);
		if(i==3&&s3+1<=n/2)dfs(idd+1,s1,s2,s3+1,sum+x[idd].c);
	}
}
void solve(){
	ans=0;
	read(n);
	for(int i=1;i<=n;i++)read(x[i].a),read(x[i].b),read(x[i].c);
	dfs(1,0,0,0,0);
	cout<<ans<<'\n';
}
signed main(){
	in("club.in")
	out("club.out")
	read(T);
	while(T--)solve();
	return 0;
}
