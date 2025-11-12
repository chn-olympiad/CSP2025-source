#include<bits/stdc++.h> 
using namespace std;
int n,k,a[100000010],j=1,ans;
int main(){
	freopin("xor.in","r",stdin);
	freopin("xor.out","w",stdout);
	//cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k)ans++;
		else if(a[i]&a[j]==k)ans++;
		else j++;
	}
	cout<<ans<<"\n";
	return 0;
}
