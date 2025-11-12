#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[1005],c[1005],f[1005];
void dfs(int x,int cnt){
	//cout<<x<<" "<<cnt<<endl;
	if(x>n){
		ans=max(ans,cnt);
		return ;
	}
	while(c[x]==0&&x<n) x++;
	if(c[x]!=0) dfs(c[x]+1,cnt+1);
	dfs(x+1,cnt);
	return ;
}
//xor:x^=y;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		f[i]=a[i];
		if(a[i]==k){
			c[i]=i;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			f[j]=f[j-1]^a[j];
			if(f[j]==k){
				c[i]=j;
				break;
			} 
		} 
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
