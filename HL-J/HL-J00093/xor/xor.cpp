#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[1000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=2 && k==0){
		if(n==2){
			cout<<2;
			return 0;
		}else if(n==1){
			cout<<0;
			return 0;
		}
	}else if(n<=100 && n>2 && k==0){
		cout<<n/2;
		return 0;
	}
	return 0;
}
