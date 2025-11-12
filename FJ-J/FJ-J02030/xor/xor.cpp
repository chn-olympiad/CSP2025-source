#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,k;
int a[100005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	if(flag==0){
		cout<<0;
	}
	else{
		cout<<1;
	}
	
	return 0;
}
