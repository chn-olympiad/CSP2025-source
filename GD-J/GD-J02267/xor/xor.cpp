#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[500010];
int pre[500010];
int cnt[500010];
int ans=0;
int pre2[500010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	pre[0]=0;
	//int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		pre2[i]=pre[i]^k;
		//cout<<pre[i]<<" "<<pre2[i]<<endl;
		//cout<<pre[i]<<" ";
	}	
	int f=0;
	int now=1;
	cnt[0]=1; 
	for(int i=1;i<=n;i++){
		if(cnt[pre2[i]]){
			//cout<<pre[i]<<" "<<pre2[i]<<endl;
			ans++;
//			cnt[pre[i]]=0;
//			cnt[pre2[i]]=0;
			for(int j=0;j<i;j++) cnt[pre[j]]=0;
			f=1;
		}
		cnt[pre[i]]=1;
	}
	cout<<ans;
	//cout<<endl;
//		dfs(1,0);
//		cout<<ans;

}
