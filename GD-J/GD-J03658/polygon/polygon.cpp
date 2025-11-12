#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005];
int ans=0;int n;
int cnt=0;
void dfs(int ceng,int last,int maxl){
	if(ceng>=3&&cnt>=maxl*2){
		ans++;
	}
	for(int i=last+1;i<=n-2;i++){
		cnt+=a[i];
		dfs(ceng+1,i,max(maxl,a[i]));
		cnt-=a[i];
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopne("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n-2;i++){
		cnt+=a[i];
		dfs(2,i,i);
		cnt-=a[i];
	}
	cout<<ans;
	return 0;
} 
