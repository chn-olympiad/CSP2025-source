#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r,x,ans1,ans2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])x++;
	}
	x++;
	if(x%n==0)ans1=x/n;
	else ans1=x/n+1;
	if(x%n==0){
		if(ans1%2==1)ans2=n;
		else ans2=1;
	}else{
		if(ans1%2==1){
			ans2=x%n;
		}else{
			ans2=n-x%n+1;
		}
	}
	cout<<ans1<<' '<<ans2;
	return 0;
	
}
