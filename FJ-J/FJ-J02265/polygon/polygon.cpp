#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,k,maxn,maxn1,ans,a[N],c[N];
bool b[N];
void dfs(int id){
	if(id>n||k>id)return;
	if(k>=3){
		int sum=0;
		for(int i=1;i<=k;i++){
			sum+=c[i]; 
		}
		if(sum>2*maxn){
			ans++;ans%=998;ans%=353;ans%=244;
		}
		return;
	}
	for(int i=id;i<=n;i++){
		if(b[id]==0){
			b[id]=1;
			c[++k]=a[i];
			maxn1=maxn;maxn=max(maxn,a[i]);
			dfs(id+1);
			b[id]=0;
			c[k--]=0;
			maxn=maxn1;
		}
		dfs(id+1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1||n==2){
		cout<<0;return 0;
	}
	if(n==3){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn)cout<<1;
		else cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
} 
