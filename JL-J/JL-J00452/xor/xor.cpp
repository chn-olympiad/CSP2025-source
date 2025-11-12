#include <bits/stdc++.h>
using namespace std;
long long n,a[5001],x,f=0,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0){
			f=1;
			ans=1;
		}
	}
	if(!f) ans=2;
	cout<<ans<<endl;
	return 0;
}
