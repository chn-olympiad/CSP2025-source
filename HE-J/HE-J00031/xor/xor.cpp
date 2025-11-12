#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int32_t main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0,s=a[1];
	for(int i=2;i<=n;i++){
		if(s==k) sum++,s=a[i+1];
		s^=a[i];
	}
	cout<<sum;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
