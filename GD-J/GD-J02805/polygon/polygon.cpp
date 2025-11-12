#include<bits/stdc++.h>
using namespace std;
long long a[5005],b[5005],sum;
int n;
inline void dfs(int q){
	if(q>n){
		long long ssum=0,ma=-1;
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				ssum+=a[i];
				ma=max(ma,a[i]);
			}
		}
		if(ssum>2*ma&&ssum!=0){
			sum++;
			sum%=998244353;
		}
		return;
	}
	b[q]=1;
	dfs(q+1);
	b[q]=0;
	dfs(q+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<sum;
}
