#include<bits/stdc++.h>
using namespace std;
const int N=5005;
long long n,a[N],s[N],t,maxx,ans;
bool v[N];
void dfs(int x,int d){
	if(x<=0) return;
	ans++;
	for(int i=d;i>=1;i--){
		if(x>a[i]&&!v[i]){
			v[i]=1;
			dfs(x-a[i],i);
			v[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		memset(v,0,sizeof(v));
		int res=s[i-1]-a[i];
		dfs(res,i-1);
	}
	cout<<ans;
	return 0;
} 
