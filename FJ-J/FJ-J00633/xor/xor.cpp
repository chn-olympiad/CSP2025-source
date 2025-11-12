#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[510000];
int n,k,t1=0,t2=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			t1++;
		}
		if(a[i]==0){
			t2++;
		}
	}
	if(k==0){
		cout<<t1/2+t2/2;
	}else if(k==1){
		cout<<max(t1,min(t1,t2))<<endl;
	}
	return 0;
}
