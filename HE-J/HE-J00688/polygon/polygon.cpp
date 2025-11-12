#include<bits/stdc++.h>
using namespace std;
int n;
int ask[500010];
long long an=0;
void dfs(int id,int mx,long long h,int p){
	if(id>n){
		return ;
	}
	if(h>mx*2&&p>=3&&id==n){
		an++;
		an%=998244353ll;
	}
	id++;
	dfs(id,max(mx,ask[id]),h+ask[id],p+1);
	dfs(id,mx,h,p);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ask[i];
	}
	dfs(0,0,0,0);
	cout<<an;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
