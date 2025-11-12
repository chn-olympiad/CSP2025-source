#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt=0;
bool flag=true,s=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=1) flag=false;
		else cnt++;
	}
	if(flag&&k==0){
		cout<<n/2;
		return 0;
	} 


	return 0;
}
