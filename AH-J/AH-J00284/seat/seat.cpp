#include<bits/stdc++.h>
using namespace std;
int a[110],n,m,r,vis;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1);
	//for(int i=1;i<=m*n;i++) cout<<a[i]<<" ";
	//cout<<endl;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			//cout<<i<<endl;
			vis=n*m-i+1;
			break;
		}
	}//cout<<vis<<endl;
	int a=vis/n,b=vis%n;
	//cout<<a<<" "<<b<<endl;
	if(b==0){
		if(a%2==0) cout<<a<<" "<<1;
		else cout<<a<<" "<<m;
	}else{
		cout<<++a<<" ";
		if(a%2==1) cout<<b;
		else cout<<n+1-b;
    }	
	return 0;
}
