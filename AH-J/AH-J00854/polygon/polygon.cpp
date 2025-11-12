#include<bits/stdc++.h>
using namespace std;
int n;
__int128 c(int N,int M){
	double sum=1;
	for(int i=1;i<=M;i++){
		sum*=N-i+1;
		sum/=i;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans+=c(n,i);
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
