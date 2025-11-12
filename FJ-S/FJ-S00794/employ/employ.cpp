#include<bits/stdc++.h>
using namespace std;
long long n,m,s,a[505],b,sum;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	b=n-m+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(b){
		sum+=b;
		b--;
	}
	cout<<sum;
	return 0;
}
