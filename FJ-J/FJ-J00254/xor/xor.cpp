#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[500010];

void solve1(){
	int sum=0;
	for(int i=1;i<n;i+=2){
		sum+=n-i;
	}
	cout<<sum;
	return ;
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	solve1();
	return 0;
}
