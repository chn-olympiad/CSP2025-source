#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int cnt0=0,cnt1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)cnt0++;
		if(a[i]==1)cnt1++;
	}
	//0 0 0 1 0 1
	if(k==0)cout<<cnt0;
	else if(k==1)cout<<cnt1;
	
	return 0;
}
