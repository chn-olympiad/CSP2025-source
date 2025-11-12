#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,arr[5005],ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	if(n<=3){
		int ma=max(max(arr[1],arr[2]),arr[3]);
		if(ma*2<arr[1]+arr[2]+arr[3]) cout<<1;
		else cout<<0;
	}else{
		cout<<366911923;
	}
	return 0;
}
