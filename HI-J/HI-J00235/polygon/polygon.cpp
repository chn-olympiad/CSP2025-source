#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
int a[5010];
bool cmp(int A,int B){
	return A>B;
}
void dfs(int sum,int id,int ma,int r){
	if(id>=n){
		if(sum<=2*ma){
			return;
		}
		if(r>=3){
			ans++;
			ans%=998244353;
		}
		return;
	}
	dfs(sum+a[id],id+1,max(ma,a[id]),r+1);
	
	dfs(sum,id+1,ma,r);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n,cmp);
	dfs(0,0,0,0);
	cout<<ans%998244353;
	return 0;
}
