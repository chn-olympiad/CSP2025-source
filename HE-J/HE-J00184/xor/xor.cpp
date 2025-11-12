#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+666;
int a[N],n,k,ans;
bool flag=1;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	if(flag&&k==0){
		cout<<n/2;
		return 0;
	}
	for(int l=1;l<=n;l++){
		int sum=0;
		int r=l;
		while((sum!=k&&r<=n)||r==l){
			sum^=a[r];
			r++;
		}
		if(sum==k)l=r-1,ans++;
	}
	cout<<ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
