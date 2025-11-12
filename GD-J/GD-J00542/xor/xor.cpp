#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ont","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long num=0,ans=0;
	for(int i=1;i<=n;i++){
		num^=a[i];
		if(num==m){
			ans++;
			num=0;
		}
	}
	cout<<ans;
	return 0;
}
