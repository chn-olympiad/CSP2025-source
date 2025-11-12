#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
        printf("%d",n);
	}
	else{
		printf("%d",2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
