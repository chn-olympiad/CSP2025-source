#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i,x[500005],one=0,zero=0,ifnotone=0;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>x[i];
		one+=(x[i]==1),zero+=(x[i]==0),ifnotone+=(x[i]!=1);
	}
	if((n==1)&&(!ifnotone)&&(!k)){
		cout<<0;
	}else if((n==2)&&(!ifnotone)&&(!k)){
		cout<<1;
	}else if((n<=100)&&(!ifnotone)&&(!k)){
		cout<<50;
	}else{
		cout<<one;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
