#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
		}
	}
	for(int i=2;i<=n;i++){
		int sum=a[i];
		for(int j=i+1;j<=n;j++){
			sum=sum^a[j];
			if(sum==k){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}