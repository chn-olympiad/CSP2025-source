#include<bits/stdc++.h>
using namespace std;
long long l,r,n,a[5010],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}	
	if(a[n]*2<=sum){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

