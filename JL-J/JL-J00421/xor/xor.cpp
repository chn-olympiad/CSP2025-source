#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	if(k==0){
		if(ans<n){
			cout<<n-ans<<endl;
		}else if(ans==n){
			cout<<0<<endl;
		}
	}else if(k==1){
		if(ans<n){
			cout<<ans<<endl;
		}else if(ans==n){
			cout<<n<<endl;
		}
	}else{
		cout<<n<<endl;
	}
	return 0;
}
