#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0,ans=0,b=0,c=0,d=0;
	int a[1005];
	cin>>n>>m;
	d=n*m;
	for(int i=1;i<=d;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+d+1);
	for(int i=1;i<=d;i++){
		if(a[i]==cnt){
			ans=d+1-i;
			break;
		}
	}
	b=((ans-1)/n)+1;
	if(b%2==1){
		c=ans-(b-1)*n;
	}
	else if(b%2==0){
		c=n+1-ans+(b-1)*n;
	}
	cout<<b<<" "<<c;
	return 0;
} 
