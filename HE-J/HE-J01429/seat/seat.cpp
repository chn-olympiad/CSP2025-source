#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200],q=1,f;
long long r,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
for(int i=2;i<=n*m;i++){
	if(a[i]>a[1]){
		q++;
	}
}
c=q/n;
if(q%n!=0){
	c++;
}
q=q%n;
if(c%2==0){
	r=c-q+1;
}
else{
	if(q==0)
	{
		r=n;
	}
	else{
	
	r=q;}
}
cout<<c<<" "<<r<<endl;
	return 0;
}

