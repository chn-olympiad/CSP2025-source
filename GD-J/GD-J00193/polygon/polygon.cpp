#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int a[505]; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	int n,maxn=-1,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	cout<<(maxn*2<sum);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

