#include<bits/stdc++.h>
using namespace std;
int sum[1000005];
int main(){
	//不同为一 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,l=0,y=0;
	bool A=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>sum[i];
		if(sum[i]!=1)A=1;
		if(sum[i]==1)y++;
		if(sum[i]==l)l++;
	}
	if(k==0&&A==0){
		if(n%2==0)cout<<n;
		else cout<<n-1;
	}else{
		if(k==0)cout<<l-l%2+y-y%2;
		else cout<<n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}  
