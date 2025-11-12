#include<bits/stdc++.h>
using namespace std;
int a[20][20],n,m,R,cnt,b,d,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>R;
	for(int i=0;i<n*m-1;i++)
	{
		cin>>b;
		if(b>R)cnt++;
	}
	cnt++;
	c=(cnt-1)/n+1;
	b=(cnt-1)%n;
	
	if(c%2==0){
		r=n-b;
	}
	else{
		r=b+1;
	}
	cout<<c<<' '<<r;
	return 0;
}