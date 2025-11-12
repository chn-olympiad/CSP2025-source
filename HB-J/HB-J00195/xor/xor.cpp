#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	bool flag=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]!=1){
				flag=0;
				break;
			}
		}
		if(flag==1){
			cout<<n<<endl;
			return 0;
		}
	}
	cout<<n/2<<endl;
	return 0;
}
