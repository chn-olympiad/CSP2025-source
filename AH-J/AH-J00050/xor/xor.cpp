#include<bits/stdc++.h>
using namespace std;
int n,k,a[514514],sum[114514];
int dp[514514];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//cout<<(1^0)<<' '<<(1^1)<<' '<<(0^0)<<endl;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	//	cout<<sum[i]<<' ';
    }
    //for(int i=1;i<=n;i++){
	//    for(int j=i;j<=n;j++){
	//		cout<<i<<' '<<j<<' '<<int(sum[j]^sum[i-1])<<endl;
	//	}
	//}
	int as=0;
    for(int i=1;i<=n;i++){
		if(a[i]==k)as++;
	}cout<<as;
    return 0;
}
