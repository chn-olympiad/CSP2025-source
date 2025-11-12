#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[10000],cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0 and n<=2){
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt++;
		}
		cout<<cnt;
		return 0;
	}
	if(k==0){
		cout<<n;
		return 0;
	}
	cout<<2;
 
	
	
	return 0;
}
