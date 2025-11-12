#include<bits/stdc++.h>
using namespace std;
struct cide{
	int l;
	int r;
}a2[1000];
long long a1[1000]={0};
int n;
bool f[1000]={0};
long long k;
int maxx=0;
void dfs(int r,int ans){
	if(r >= n){
		maxx = max(maxx,ans);
		return;
	}
	
	for(int i = a2[r].r;i<=n;i++){
		if(f[i]){
			dfs(i,ans+1);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a1[i];
	}
	bool flag=0;
	for(int i=1;i<=n;i++){
		long long ans = 0;
		for(int j=i;j<=n;j++){
			ans=(ans^a1[j]);
			if(ans == k){
				f[i]=1;
				flag=1;
				a2[i].l=i;
				a2[i].r=j;
				break;
			}
		}
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<maxx;
}

