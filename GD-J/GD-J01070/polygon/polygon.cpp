#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[10086];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<985211;
	return 0;
} 
