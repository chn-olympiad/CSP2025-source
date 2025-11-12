#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],pre,ans,sum[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=pre+1;j<=i;j++)sum[j]^=a[i];
		for(int j=pre+1;j<=i;j++){
			if(sum[j]==k){
				pre=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
