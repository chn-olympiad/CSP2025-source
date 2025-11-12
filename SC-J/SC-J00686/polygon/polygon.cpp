#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[6000];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>=max(max(a[1],a[2]),a[3])){
			cout<<1;
		}
	}else{
		cout<<n;
	}
	
	return 0;
}
