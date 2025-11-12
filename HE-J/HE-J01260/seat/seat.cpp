#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],x,y,z,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	z=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>0;i--){
		if(a[i]==z){
			k=n*m-i+1;
			break;
		}
	}
	if(k%n==0) x=k/n;
	else x=k/n+1;
	if(x%2==0) y=(n-k%n)+1;
	else{
	if(k%n==0) y=n;
	else y=k%n;	
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
