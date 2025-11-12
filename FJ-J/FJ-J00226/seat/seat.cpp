#include<bits/stdc++.h>
using namespace std;
int a[200],m,n,r;
int i,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	r=a[1];
	for(i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m);
	i=n*m;
	while(r!=a[i]){
		i--;
	}
	s=m*n-i+1;
	//lie
	int j=s/m;
	if(s%m!=0)j++;
	//hang
	i=s%(n*2);
	if(i>n)i=2*n-i+1;
	else if(i==0)i=1;
	
	cout<<j<<" "<<i;
	return 0;
}


