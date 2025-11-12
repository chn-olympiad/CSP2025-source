#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,k,a[N],maxn;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int ans=a[1],sum=0;
		for(int j=2;j<i;j++){
			ans^=a[j];
		}if(ans==k) sum++;
		ans=a[i];
		for(int j=i+1;j<=n;j++){
			ans^=a[j];
		}if(ans==k) sum++;
		if(sum>maxn) maxn=sum;
	}cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
