#include<bits/stdc++.h>
using namespace std;
int n,a[5002];
int ans;
bool t[5002];
void dfs(int step,int cnt,int maxis,int longis){
	if(step==n){
		if(cnt>2 and longis>2*maxis){
			ans++;
			ans%=998244353;
			/*for(int i=1;i<=step;i++){
				if(t[i])cout<<a[i]<<" ";
			}
			cout<<longis<<" "<<maxis<<" "<<cnt<<" "<<step<<endl;*/
		}
		return;	
	}
	t[step+1]=1;
	dfs(step+1,cnt+1,max(maxis,a[step+1]),longis+a[step+1]);
	t[step+1]=0;
	dfs(step+1,cnt,maxis,longis);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
