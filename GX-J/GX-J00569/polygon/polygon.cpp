#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n;
long long a[5001],b[5001],vis[5001];
long long cnt,mann,ans=0;
void dfs(int s,int o){
	if(s>=3){
		cnt=0;
		mann=-1;
		for(int i=1;i<=s;i++){
		    mann=max(mann,b[i]);
		    cnt+=b[i];
		}
		
		if(cnt>mann*2){
			ans++;
			ans=ans%p;
		}
	}
	for(int i=o;i<=n;i++){
		if(vis[i]==1||b[s]>a[i])continue;
		b[s+1]=a[i];
		vis[i]=1;
		dfs(s+1,i+1);
		vis[i]=0;
		b[s+1]=a[i];
	}
	return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<500){
		sort(a+1,a+1+n);
		dfs(0,1);
		cout<<ans;
	}
	else {
		long long k=n*(n-1)/2;
		b[1]=1;
		for(int i=1;i<=n;i++){
			b[i]=(b[i-1]*2+1)%p;
		}cout<<((b[n]-n)%p-k)%p;
	}
	return 0;
}

