#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,k;
int a[N];
int sum;
map<int,int>t;
int ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		sum^=a[i];
		if(t[k^sum]||sum==k){
			ans++;
			sum=0;
			t.clear();
		}
		t[sum]++;
	}
	cout<<ans;
}
