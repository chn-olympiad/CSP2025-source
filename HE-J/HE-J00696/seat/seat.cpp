#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,ans=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n*m-1;i++){
		cin>>b;
		if(b>a) ans++;
	}
	double x=n;
	cout<<ceil(ans/x)<<' ';
	if(int(ceil(ans/x))%2==1){
		if(ans%n==0) cout<<n;
		else cout<<ans%n;
	}
	else{
		cout<<n-(ans%(n+1));
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
