#include<bits/stdc++.h>
using namespace std;
int a[123];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int rt=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1])rt++;
	}
	int c=(rt+n-1)/n,r=(rt-1)%n+1;
	if(c%2==0)r=n+1-r;
	cout<<c<<' '<<r<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
