#include<bits/stdc++.h>
#include<cmath> 
using namespace std;
 bool s(int x,int y){
 	return x>y;
 }
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110],num,b,c,ans;
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
		if(i==1){
			b=a[i];
		}
	}
	sort(a+1,a+num+1,s);
	for(int i=1;i<=num;i++){
		if(a[i]==b){
			c=i;
			break;
		}
	}
	if(c>n){
		ans=c/n+1;
	}
	else{
		ans=1;
	}
	cout<<ans<<" ";
	if(ans%2==1){
		cout<<c-(ans-1)*n;
	}
	else{
		cout<<ans*n-c+1;
	}
	return 0;
} 
