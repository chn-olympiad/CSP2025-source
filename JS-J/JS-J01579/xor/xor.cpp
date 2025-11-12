#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],sum[N];
int ans;
int pos[4000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int l=0;
	for(int i=1;i<=n;i++){
		if((sum[i]^sum[l])==k){
			ans++;
			l=i;
		}else if(pos[k^sum[i]] && pos[k^sum[i]]>l){
			ans++;
			l=i;
		}
		pos[sum[i]]=i;
	}
	cout<<ans;
	return 0;
}

