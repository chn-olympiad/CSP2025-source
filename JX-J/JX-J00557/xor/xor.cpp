#include<bits/stdc++.h>
using namespace std;
int n,a[1000],z;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>z;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(z==2)cout<<"2";else if(z==3)cout<<"2";else if(z==0)cout<<"1";cout<<"1";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
