#include<bits/stdc++.h>
using namespace std;
int b=1,n,m,a[105],p,num,ans,ans1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	while(b){
		b=0;
		for(int i=1;i<=n*m;i++){
			if(a[i]<a[i+1]){
				p = a[i];
				a[i] = a[i+1];
				a[i+1] =p;
				b=1;
			}
		}	
	}
	for(int i=1;i<=n*m;i++){
		if(num==a[i]){
			ans=i;
			break;
		}
	}
	if(ans!=n){
		ans1=ans%n;
	}
	else{
		ans1=n;
	}
	ans = ans/(n+1)+1;
	cout<<ans<<" "<<ans1;
	return 0;
}
