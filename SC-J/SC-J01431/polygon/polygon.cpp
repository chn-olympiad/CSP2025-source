#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[50005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=3){
		if(sum>maxn*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	return 0;
}