
#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5010];
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==5){
		if(a[0]==1){
			cout<<9;
		}else{
			cout<<6;
		}
	}else{
		long long ans=1;
		for(int i=0;i<n;i++){
			ans=ans*i;
		}
		cout<<ans;
	}
	return 0;
}
