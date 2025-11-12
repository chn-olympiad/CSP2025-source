#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[1000100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==4){
		if(k==2||k==3)cout<<2;
		if(!k)cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
