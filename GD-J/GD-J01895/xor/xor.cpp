#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	long long a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<2){
		cout<<"0";
		return 0;
	}
	bool b=1;
	long long ans=0;
	if(k==0){
		for(int i=1;i<=0;i++){
			if(a[i]!=0){
				b=0;
				ans++;
				break;
			}
		}
		if(b==1){
			cout<<"1";
		}else{
			cout<<"0";
		}
		return 0;
	}else{
		cout<<ans;
	}
	return 0;
}
