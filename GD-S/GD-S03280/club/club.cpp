#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],c[maxn];
int n;
int dfs(int i,int a1,int b1,int c1,int ans){
	if (i==n+1) return ans;
	if (a1==n/2){
		return max(dfs(i+1,a1,b1+1,c1,ans+b[i]),dfs(i+1,a1,b1,c1+1,ans+c[i]));
	}
	if (b1==n/2){
		return max(dfs(i+1,a1+1,b1,c1,ans+a[i]),dfs(i+1,a1,b1,c1+1,ans+c[i]));
	}
	if (c1==n/2){
		return max(dfs(i+1,a1+1,b1,c1,ans+a[i]),dfs(i+1,a1,b1+1,c1,ans+b[i]));
	}
	return max(max(dfs(i+1,a1,b1,c1+1,ans+c[i]),dfs(i+1,a1+1,b1,c1,ans+a[i])),dfs(i+1,a1,b1+1,c1,ans+b[i]));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		cout<<dfs(1,0,0,0,0)<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
