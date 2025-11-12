#include<bits/stdc++.h>
using namespace std;
int t,n,ans,p;
struct node{
	int a,b,c,id;
}x[500005];
bool cmp(node rp,node ll){
	return rp.a>ll.a;
}
long long c1(){
	long long sum=0;
	for(int i=1;i<=n;i++)
		sum+=x[i].b;
	return sum;
}
long long c2(){
	long long sum=0;
	for(int i=1;i<=n;i++)
		sum+=x[i].c;
	return sum;
}
void dfs(int k,int aa,int bb,int cc,int sum){
	if(k>n){
		ans=max(sum,ans);
		return ;
	}
	if(aa<p)dfs(k+1,aa+1,bb,cc,sum+x[k].a);
	if(bb<p)dfs(k+1,aa,bb+1,cc,sum+x[k].b);
	if(cc<p)dfs(k+1,aa,bb,cc+1,sum+x[k].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;p=n/2;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			x[i].id=i;
		}
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
			ans=0;
			continue;
		}
		long long d2=c1(),d3=c2();
		if(d2+d3==0){
			sort(x+1,x+n+1,cmp);
			for(int i=1;i<=p;i++)
				ans+=x[i].a;
			cout<<ans<<'\n';
			ans=0;
		}
	}
	return 0;
}
