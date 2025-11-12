#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500002],b[500002],ans;
bool A(){
	for(int i=1;i<=n;i++) if(a[i]!=1) return 0;
	return 1;
}
bool B(){
	for(int i=1;i<=n;i++) if(a[i]>=2) return 0;
	return 1;
}
int summ(){
	int num=0;
	for(int i=1;i<=n;i++) if(a[i]) num++;
	return num;
}
int summm(){
	int num=0;
	for(int i=1;i<n;i++) if(a[i]==1&&a[i+1]==1) num++,i++;
	return num;
}
void dfs(int j,int num){
	if(j>n){
		ans=max(ans,num);
		return;
	}
	for(int i=j;i<=n;i++) if((b[i]^b[j-1])==k) dfs(i+1,num+1);
	dfs(j+1,num);
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	if(A()) cout<<(k?n:n/2);
	else if(B()) cout<<(k?summ():n-summ()+summm());
	else{
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}