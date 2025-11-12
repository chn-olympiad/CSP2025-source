#include <bits/stdc++.h>
using namespace std;
int a[500005];
int n,k;
bool check(int x,int l[],int r[]){
	for(int i=1;i<=x;i++){
		for(int j=1;j<=x;j++){
			for(int p=1;p<=x;p++){
				if(p==x){
					continue;
				}
				for(int q=1;q<=x;q++){
					if(j==q){
						continue;
					}
					int t1=a[i+1],t2=a[p+1];
					for(int t=i+1;t<=j;t++){
						t1=t1 xor a[t];
					}
					for(int t=p+1;t<=q;t++){
						t2=t2 xor a[t];
					}
					if(t1==k && t2==k){
						return true;
					}
				}
			}
		}
	}
	return false;
}
int ans;
void dfs(int x,int l[],int r[]){
	if(x==n+1){
		return;
	}
	if(check(x,l,r)){
		ans++;
	}
	dfs(x+1,l+a[x],r+a[x]);
	dfs(x+1,l+a[x],r);
	dfs(x+1,l,r+a[x]);
	dfs(x+1,l,r);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,{0},{0});
	cout<<ans+2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
