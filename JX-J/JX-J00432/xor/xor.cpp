#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],ans;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=0;i<n;i++){
	cin>>a[n];
	if(a[n]==k)ans++;
}
cout<<ans;
	return 0;
}
