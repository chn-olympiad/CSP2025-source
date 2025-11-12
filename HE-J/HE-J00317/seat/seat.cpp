#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[101],b=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,h;
	cin>>n>>m;
	cin>>h;
	for(int i=1;i<n*m;i++){
		ll t;
		cin>>t;
		if(t>h)b++;
	}
	h=1;
	if(int(b/n)%2==0&&b%n!=0){
		cout<<int(b/n)+1<<" "<<b%n;
		h=0;
	}
	if(h==1&&int(b/n)%2==0&&b%n==0){
		cout<<int(b/n)<<" "<<1;
		h=0;
	}
	if(h==1&&int(b/n)%2!=0&&b%n!=0){
		cout<<int(b/n)+1<<" "<<n-b%n+1;
		h=0;
	}
	if(h==1&&int(b/n)%2!=0&&b%n==0){
		cout<<int(b/n)<<" "<<n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
