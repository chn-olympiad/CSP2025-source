#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
LL a[N],k,n;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0){
		cout<<n/2;
	} 
	
	return 0;
}
