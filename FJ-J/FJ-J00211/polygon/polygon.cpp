#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2) cout<<1;
		else cout<<0;
	}
	else{
		int m=n-2;
		if(m%2==0) cout<<((m/2)+(m/2+1))*(m/2);
		else cout<<(m/2+1)*m;
	}
	
	return 0;
}
