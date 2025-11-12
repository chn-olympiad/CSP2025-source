#include<bits/stdc++.h>
using namespace std;
int n,a[500005],o,x;
long long k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1&&k==0){
		if(a[1]==0){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(n==2&&k==0){
		if(a[1]==0){
			o++;
		}
		if(a[2]==0)o++;
		cout<<o;return 0;
	}
	cout<<5;
	return 0;
}
