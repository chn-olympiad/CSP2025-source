#include <bits/stdc++.h>
using namespace std;
int a[500005];
int pre[500005];
map<int,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i!=1){
			pre[i]=pre[i-1]^a[i];
		}else{
			pre[i]=a[i];
		}
	}
	int ans=0;
	int la=0;
	for(int i=1;i<=n;i++){
		if(pre[i]==k&&la<1){
			ans++;
			continue;
		}
		if(a[i]==k){
			ans++;
			la=i;
			mp[pre[i]]=i;
			continue;
		}
		if(mp[pre[i]^k]>=la&&mp[pre[i]^k]!=0){
			ans++;
			la=i;
		}
		mp[pre[i]]=i;
	}
	printf("%d\n",ans);
	return 0;
}
