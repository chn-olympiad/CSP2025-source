#include<bits/stdc++.h>
using namespace std;
int n,k,a[1010111],sum[1001011],sum1[1001011],ans;
vector<int>t[10000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i],sum[i]=sum[i-1]^a[i];
		t[sum[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int op=k^sum[i-1];
		if(t[op].size()>0){
			sum1[t[op][0]]=max(1,sum1[t[op][0]]);
			int l=0;
			for(int j=i-1;j>=1;j--) l=max(l,sum1[j]+1);
			sum1[t[op][0]]=max(sum1[t[op][0]],l);
		}
	}
	for(int i=1;i<=n;i++) ans=max(ans,sum1[i]);
	cout<<ans;
	return 0;
	
}
