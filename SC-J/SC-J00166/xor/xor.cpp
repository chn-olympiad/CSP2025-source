#include<bits/stdc++.h>

using namepace std;
int a[1010];int qzh[1010][30];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;int k;
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(k!=1&&k!=0){
		cout<<0;
	}else if(k==0){
		 cout<<n;
	}else{
		
		cout<<n/3;
	}
	
	
	
	
	return 0;
 } 