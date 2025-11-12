#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n+1],b[n+1];
	a[0]=0;
	b[0]=0;
	for(int i=1;i<=n;i++) cin>>a[n];
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		sort(a+1,a+n+1);
		if((a[1]+a[2]+a[3])>2*a[3]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	
	return 0;
}
