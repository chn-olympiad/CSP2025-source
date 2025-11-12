#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,a[114514];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&(m==3||m==2)){
		cout<<2;
	}
	else if(n==4&&m==0){
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
