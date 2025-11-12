#include<bits/stdc++.h>
using namespace std;
const int N=600;
long long n,m,ans;
char dmnd[N];
struct node{
	long long ns;
	bool f;
}a[N];
void dfs(int rs,int tt,int k){
	//cout<<rs<<' '<<tt<<' '<<k<<endl;=
	if(rs==m){
		ans++;
		ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[i].f){
			a[i].f=false;
			if(a[i].ns>tt){
				if(dmnd[k]=='0')dfs(rs,tt+1,k+1);
				else dfs(rs+1,tt,k+1);	
			}else dfs(rs,tt+1,k+1);
			a[i].f=true;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>dmnd[i];
	for(int i=1;i<=n;i++){
		cin>>a[i].ns;
		a[i].f=true;
	}
	dfs(0,0,1);
	cout<<ans;
	return 0;
}
