#include <bits/stdc++.h>
using namespace std;
int n,m,a[102],ans=0,b,c,d,e;

int main(){
	freopen ("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	 
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			ans++;
		cin>>a[ans];
	}
}
	b=a[1];
	sort (a+1,a+1+ans);
	//for (int i=1;i<=ans;i++){
	//	cout<<a[i]<<" ";
	//}
	for (int i=ans;i>=1;i--){
		if (a[i]==b){
			c=ans-i+1;
	}
}
	if (c%n==0){
		d=c/n;
		cout<<d;
		e=c%n;
		}else {
			d=c/n+1;
			cout<<d;
			e=c%n;
		}
		cout<<" ";
		if (d%2==1){
			if (e==0){
			cout<<n;
			}else{cout<<e;}
			
		}else{
			if (e==0){
				cout<<1;
				}else{
			cout<<n-e+1;}
			}
			//cout<<endl;
			//cout<<ans<<" "<<b<<" "<<c<<" "<<d<<" "<<e;
	return 0;
}
