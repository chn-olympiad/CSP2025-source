//seat
#include<bits/stdc++.h>
using namespace std;
long long n,m,a,x,t=1,h;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a; 
		if(i==1) x=a;
		else{
			if(a>x) t++;
		}
	}
	h=t/n;//¼¸ÁÐ 
	if(t%n==0){
		if(h%2==0){
			cout<<h<<" "<<1;
		} 
		else{
			cout<<h<<" "<<n;
		}
	}
	else{
		if(h%2==0){
			cout<<h+1<<" "<<t%n;
		} 
		else{
			cout<<h+1<<" "<<n-(t%n)+1;
		}
	}
	return 0;
} 
