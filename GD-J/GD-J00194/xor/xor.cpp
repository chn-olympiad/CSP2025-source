#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1005],pre[1005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,laspos=-1,ans=0;
	cin>>n>>k;
	cin>>a[1];
	pre[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			if(i<=laspos)ans--;
			ans++;
			laspos=i;
			continue;
		}
		int cur=-1;
		for(int j=i+1;j<=n;j++){
			if((pre[j]^pre[i-1])==k){
				cur=j;
				ans++;
				break;
			}
		}
		if(i<=laspos&&cur!=-1){
			ans--;
			laspos=min(laspos,cur);
		}
		else if(cur!=-1)laspos=cur;
	}
	cout<<ans;
	return 0;
}
