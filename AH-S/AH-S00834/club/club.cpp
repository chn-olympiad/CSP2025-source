#include<bits/stdc++.h>
using namespace std;
int t,n,ans,f[105][55][55][55];
struct student{
	int a,b,c;
}d[100005],b[100005];
int dfs(int a,int b,int c,int x){
	if(x>n){
		return 0;
	}
	if(f[x][a][b][c]){
		return f[x][a][b][c];
	}
	if(a+1<=n/2){
		f[x][a][b][c]=max(f[x][a][b][c],dfs(a+1,b,c,x+1)+d[x].a);
	}
	if(b+1<=n/2){
		f[x][a][b][c]=max(f[x][a][b][c],dfs(a,b+1,c,x+1)+d[x].b);
	}
	if(c+1<=n/2){
		f[x][a][b][c]=max(f[x][a][b][c],dfs(a,b,c+1,x+1)+d[x].c);
	}
	return f[x][a][b][c];
}
bool cmp(student x,student y){
	return x.a>y.a;
}
bool cmp1(student x,student y){
	if(x.a!=y.a){
		return x.a>y.a;
	}
	return x.b>y.b;
}
bool cmp2(student x,student y){
	if(x.b!=y.b){
		return x.b>y.b;
	}
	return x.a>y.a;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		cin>>n;
		bool flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
			if(d[i].b||d[i].c){
				flag1=0;
			}
			if(d[i].c){
				flag2=0;
			}
		}
		if(flag1){
			sort(d+1,d+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=d[i].a;
			}
			cout<<ans;
			continue;
		}
		else if(flag2){
			for(int i=1;i<=n;i++){
				b[i].a=d[i].a;
				b[i].b=d[i].b;
			}
			sort(d+1,d+n+1,cmp1);
			sort(b+1,b+n+1,cmp2);
			int ans1=0;
			for(int i=1;i<=n/2;i++){
				ans1+=d[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				ans1+=d[i].b;
			}
			int ans2=0;
			for(int i=1;i<=n/2;i++){
				ans2+=b[i].b;
			}
			for(int i=n/2+1;i<=n;i++){
				ans2+=b[i].a;
			}
			cout<<max(ans1,ans2)<<"\n";
		}
		else{
			cout<<dfs(0,0,0,1)<<"\n";
		}
	}
	return 0;
}
