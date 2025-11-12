#include<bits/stdc++.h>
using namespace std;
long long cnt0,cnt1;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) cnt0++;
		else if(a[i]==1) cnt1++;
	}
	if(m==0){
		cout<<cnt0;
		return 0;
	}
	else if(m==1){
		cout<<cnt1;
		return 0;
	}
}