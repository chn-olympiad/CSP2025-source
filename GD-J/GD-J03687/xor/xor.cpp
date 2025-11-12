#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			flag=false;
			break;
		}
	}
	if(flag){
		if(k==0){
			cout<<(n/2);
			return 0;
		}
	} 
	bool flag1=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=1&&a[i]!=0){
			flag=false;
			break;
		}
	}
	return 0;
}
