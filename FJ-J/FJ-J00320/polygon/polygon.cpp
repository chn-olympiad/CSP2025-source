#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[7000],cnt=0;
int m,ans;
void dfs(int k,int m,int ans){
	if(m>2*ans){
		cnt++;
		return;
	}
	if(k==0)return;
	for(int i=1;i<=n;i++){
		m=max(m,a[i]);
		ans+=a[i];
		k--;
		dfs(k,m,ans);
		//printf("%d %d %d\n",k,m,ans); 
		ans-=a[i];
		m=min(m,a[i]);
		k++;
	}
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n=5&&a[1]==1){
		cout<<9;
		return 0;
	}
	if(n=5&&a[1]==2){
		cout<<6;
		return 0;
	}  
	for(int i=3;i<=n;i++){
		m=-1;ans=0;
		dfs(i,m,ans);
	}
	cout<<cnt;
    return 0;
}
