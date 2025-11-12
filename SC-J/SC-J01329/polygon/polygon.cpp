#include<bits/stdc++.h>
using namespace std;
int n,a[1010];
long long ans;
void dfs(int s,int h,int m,int c){
	if(h>2*m&&s>=3){
		ans++;
		ans%=998244353;
	}
	for(int i=c;i<n;i++){
		dfs(s+1,h+a[i],max(m,a[i]),i+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
