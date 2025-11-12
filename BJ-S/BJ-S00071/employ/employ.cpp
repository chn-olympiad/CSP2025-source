#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int c[501],n,a[501],s[501],m;long long jie[501];
int df[501];long long ans;;
bool vis[501];
void dfs(int step){
	int cnt=0;
	int mx=m;
	int tot=0;
	for(int i=1;i<=step;i++){
		if(a[df[i]]>tot && c[i]==1){
			cnt++;
		}else{
			tot++;
		}
		if(cnt>=mx){
			break;
		}
	}
	if(cnt>=mx){
		//for(int i=1;i<=step;i++){
		//	cout<<a[df[i]]<<' ';
		//}cout<<endl;
		//for(int i=1;i<=step;i++){
			//cout<<vis[df[i]]<<' ';
		//}//cout<<endl;
		long long ct=jie[n-step];
		ans+=ct;
		ans%=M;
		return ;
	}
	if(step==n){
		
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=1;
		df[step+1]=i;
		dfs(step+1);
		vis[i]=0;
		df[step+1]=0;
	}
}
int main(){
	
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    jie[0]=jie[1]=1;
    for(int i=2;i<=500;i++){
		jie[i]=jie[i-1]*i%M;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		c[i]=x-'0';
		//cout<<c[i]<<' ';
	}//cout<<endl;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
