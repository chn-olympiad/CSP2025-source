#include<iostream>
using namespace std;
int n,k,a[10000005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>ans)ans=a[i];
	}
	if(ans>k)cout<<ans;
	else cout<<k;
	return 0;
}
