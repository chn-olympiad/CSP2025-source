#include<bits/stdc++.h>
using namespace std;
int a[5001],n,ans,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(ans,a[i]);
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	if(n<=2){
		cout<<0;
	}
	else if((n==3)&&(ans>(2*sum))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}