#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) m++;
	}
	if(k==0){
		if(m==0){
			cout<<n/2;
		}else{
			cout<<m;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 