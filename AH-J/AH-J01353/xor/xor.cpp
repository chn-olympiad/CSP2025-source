#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,a[N],cnt,f[N];
queue<int> q;
int dfs(int x){
	if(x>n)
		return 0;
	int s=0;
	for(int i=x;i<=n;i++){
		s=s+a[i]-2*(s&a[i]);
		if(s==k){
			if(f[i+1]==0)
				f[i+1]=dfs(i+1)+1;
			f[x]=max(f[i+1],f[x]);
		}
	}
	return f[x];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		if(f[i]==0)
			f[i]=dfs(i);
		cnt=max(cnt,f[i]);
	}
	cout<<cnt;
}
