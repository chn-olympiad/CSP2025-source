#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=2,ans=0;
	while(i<=n){
		ans+=n-i+1;
		i*=2;
	}
	cout<<ans;
	//QAQÌ«ÄÑÆ­ÁË 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
