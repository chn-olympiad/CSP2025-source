#include<bits/stdc++.h>
using namespace std;
const int N=5100,Mod=998244353;
long long n,a[N],s[N],ans;
map<int,map<int,map<int,int>>> f;
int dfs(int i,int s,int cnt){
//	cout<<i<<" "<<s<<" "<<cnt<<endl;
	if(i>n) return 0;
	if(cnt>=3&&a[i]*2<s){
		ans=(ans+1)%Mod;
//		cout<<"**************"<<i<<" "<<s<<" "<<cnt<<endl;
		return (1+dfs(i+1,s+a[i+1],cnt+1)+dfs(i+1,s,cnt))%Mod;
	}
	if(f[i][s][cnt]) return f[i][s][cnt];
	return f[i][s][cnt]=(dfs(i+1,s+a[i+1],cnt+1)+dfs(i+1,s,cnt))%Mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
