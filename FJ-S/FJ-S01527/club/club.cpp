#include<bits/stdc++.h>
#define gc() getchar()
#define r(x) (x)=read()
using namespace std;
const int N=1e5+5;
inline int read(){
	int x=0,f=1;char c=gc();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=gc();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=gc();}
	return x*f;
}
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
struct node{
	int ag[3],mx=0,mxi,mx2,mxi2;
}ag[N];
int t,n,nm[3];
inline int dfs(int x,int i,int a,int b,int c){
	if(x==0)a++;
	if(x==1)b++;
	if(x==2)c++;
	if(i==n)return ag[i].ag[x];
	int cnt=0;
	if(a<n/2)cnt=dfs(0,i+1,a,b,c);
	if(b<n/2)cnt=max(cnt,dfs(1,i+1,a,b,c));
	if(c<n/2)cnt=max(cnt,dfs(2,i+1,a,b,c));
	return cnt+ag[i].ag[x];
}
inline bool cmp(node a,node b){
	return a.mx>b.mx;
}
inline bool cmp1(node a,node b){
	return a.mx2>b.mx2;
}
inline void solve(){
	r(n);
	int ans=0;
	for(int i=1;i<=n;i++)r(ag[i].ag[0]),r(ag[i].ag[1]),r(ag[i].ag[2]);
	if(n>10){
		int cnt=0,cntx=0;
		for(int i=1;i<=n;i++){
			ag[i].mx=ag[i].ag[0],ag[i].mxi=0;
			if(ag[i].mx<ag[i].ag[1]){
				ag[i].mx2=ag[i].mx,ag[i].mxi2=ag[i].mxi;
				ag[i].mx=ag[i].ag[1],ag[i].mxi=1;
			}
			if(ag[i].mx<ag[i].ag[2]){
				ag[i].mx2=ag[i].mx,ag[i].mxi2=ag[i].mxi;
				ag[i].mx=ag[i].ag[2],ag[i].mxi=2;
			}
			if(ag[i].mxi==0){
				if(ag[i].ag[1]>ag[i].ag[2])ag[i].mxi2=1,ag[i].mx2=ag[i].ag[1];
				else ag[i].mxi2=2,ag[i].mx2=ag[i].ag[2];
			}
		}
		sort(ag+1,ag+1+n,cmp);nm[0]=nm[1]=nm[2]=0;
		for(int i=1;i<=n;i++){
			if(nm[ag[i].mxi]<n/2){
				nm[ag[i].mxi]++;
				cnt+=ag[i].mx;
			}else{
				nm[ag[i].mxi2]++;
				cnt+=ag[i].mx2;
			}
		}
		sort(ag+1,ag+1+n,cmp1);nm[0]=nm[1]=nm[2]=0;
		for(int i=1;i<=n;i++){
			if(nm[ag[i].mxi2]<n/2){
				nm[ag[i].mxi2]++;
				cntx+=ag[i].mx2;
			}else{
				nm[ag[i].mxi]++;
				cntx+=ag[i].mx;
			}
		}
		ans=max(cnt,cntx);
	}else{
		ans=dfs(0,1,0,0,0);
		ans=max(ans,dfs(1,1,0,0,0));
		ans=max(ans,dfs(2,1,0,0,0));
	}
	write(ans);putchar('\n');
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	r(t);
	while(t--)solve();
	return 0;
}
