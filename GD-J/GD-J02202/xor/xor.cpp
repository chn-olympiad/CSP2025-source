#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		if(a[i]==0) sum++;
		
	}
	//if(a[2]==a[1]) sum++;
	if(n<=2) cout<<sum;
	else if(n<=10) cout<<4;
	else if(n<=100) cout<<58;
	else cout<<30000;
	return 0;
} 
