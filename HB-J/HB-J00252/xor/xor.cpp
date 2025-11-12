#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],idx=1,ans,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=idx;i<=n;i++){
		ans^=a[i];
		if(ans==k){
			sum++;
			idx=i+1;
			ans=0;
		}
	}
	cout<<sum;
	return 0;
}
