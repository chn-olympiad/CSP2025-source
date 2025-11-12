#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,k,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	for(int i=1;i<n*m;i++){
		if(a[i]>a[0])k++;
	}
	c=k/n+1;
	r=k%n+1;
	if(c%2==0)r=n-r+1;
	cout<<c<<" "<<r<<endl;
	return 0;
}
