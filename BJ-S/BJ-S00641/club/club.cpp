#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int t,n,f[N][5],ans;
struct node{
	int a,b,c,g;
} x[N];
bool cmp(node a1,node a2){
	if (a1.g<a2.g)
		return 0;
	return 1;
}
void dfs(int fl,int a,int b,int c,int cnt){
	if (fl==n+1){
		ans=max(ans,cnt);
		return ;
	}
	if (a<n/2)
		dfs(fl+1,a+1,b,c,cnt+x[fl].a);
	if (b<n/2)
		dfs(fl+1,a,b+1,c,cnt+x[fl].b);
	if (c<n/2)
		dfs(fl+1,a,b,c+1,cnt+x[fl].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			x[i].g=x[i].a-x[i].b;
		}
		if (n<=100){
			ans=0;
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
		}
		if (n>=200){
			
			sort(x+1,x+n+1,cmp);
			ans=0;
			for (int i=1,j=n;i<=j;i++,j--){
				ans+=x[i].a+x[j].b;
			}
			cout<<ans<<'\n';
		}
		
	}
	return 0;
}