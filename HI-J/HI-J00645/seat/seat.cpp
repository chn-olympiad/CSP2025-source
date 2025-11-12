#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int num=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++) if(a[i]==num) ans=n*m-i+1;
	if(ans%n==0){
		int num1=ans/n;
		if(num1%2==1) cout<<ans/n<<" "<<n;
		else cout<<ans/n<<" "<<"1";
	}
	else{
		int num1=ans/n+1;
		if(num1%2==1) cout<<ans/n+1<<" "<<ans%m;
		else cout<<ans/n+1<<" "<<m-(ans%m)+1;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
