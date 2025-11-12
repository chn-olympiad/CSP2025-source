#include<bits/stdc++.h>
using namespace std;

long long n,ans;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n;
	ans=1;
	for(int i=2;i<=n;i++){
		ans*=i;
	}
	cout<<ans;
	
	return 0;
}
