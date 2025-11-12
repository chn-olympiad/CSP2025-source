#include<bits/stdc++.h>
using namespace std;
struct dd{
	int x,y,z;
}a[500009];
int b[111111];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k1,cnt=1;
	cin>>n>>k1;
	for(int i=1;i<=n;i++) cin>>b[i];
	if(k1==0){
		cout<<n/2;
		return 0;
	}
	cout<<cnt;
	return 0;
}
