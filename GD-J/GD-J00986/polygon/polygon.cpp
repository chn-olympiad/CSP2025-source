#include<bits/stdc++.h>
using namespace std;
signed n;int ans,temp;
int a[5010];
void dfs(int count,signed cnt,int ptr,int maxlen){
	//count:总和 cnt:计数 ptr:当前选择数 maxlen:长度最大值 
	count+=a[ptr];cnt++;
	maxlen=max(a[ptr],maxlen);
	if(cnt==temp and count>(maxlen*2)){
		ans++;return;
	}
	for(int i=ptr+1;i<n;i++){
		dfs(count,cnt,i,maxlen);
	} 
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(temp=3;temp<n;temp++){
		for(int i=0;i<n-temp+1;i++){
			dfs(0,0,i,0);
		}
	}
	ans++;
	cout<<ans%998244353;
} 
