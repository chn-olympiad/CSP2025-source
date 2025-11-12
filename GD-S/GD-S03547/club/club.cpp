#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
struct per{
	long long a,b,c,d,maxx;
}pers[N];
bool cmp1(per x,per y){
	return x.maxx>y.maxx;
}
long long dfs(int a,int b,int c,int i){
	if(a>n/2||b>n/2||c>n/2||i>n)return 0;
	return max(max(a<n/2?pers[i].a+dfs(a+1,b,c,i+1):0,b<n/2?pers[i].b+dfs(a,b+1,c,i+1):0),a<n/2?pers[i].c+dfs(a,b,c+1,i+1):0);
}
void solve(){
	long long ans=0,ansd=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b,c,d,maxx;
		cin>>a>>b>>c;
		d=min((a,b),c);
		ansd+=d;
		a-=d,b-=d,c-=d;
		if(a>=b&&a>=c)maxx=a;
		else if(b>=a&&b>=c)maxx=b;
		else maxx=c;
		pers[i]=(per){a,b,c,d,maxx};
	}
	sort(pers+1,pers+n+1,cmp1);
	cout<<dfs(0,0,0,1)+ansd<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
