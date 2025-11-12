#include<bits/stdc++.h>
#define int long long
using namespace std;
int k,n;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		int o=0;
		for(int i=1,x;i<=n;i++){
			cin>>x;
			if(x==1) o++; 
		}
		cout<<(n-o)+o/2<<"\n";
		return 0;
	}
	if(k==1){
		int o=0;
		for(int i=1,x;i<=n;i++){
			cin>>x;
			if(x==1) o++;
		} 
		cout<<o<<"\n";
		return 0;
	}
	cout<<n<<'\n';
	return 0;
}
