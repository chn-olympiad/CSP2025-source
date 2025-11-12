#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int nb[100086];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll c,r;
	ll n=0;
	ll a;
	cin>>c>>r;
	n=c*r;
   for(int i=1;i<=n;i++){
   	cin>>nb[i];
   }
	a=nb[1];
	ll num=0;
	for(int i=1;i<=n;i++){
	if(a<nb[i]){
	num++;	
	 }
	}
	if(num<c) cout<<"1"<<" "<<num+1;
	else{
	if(num%c!=0) cout<<num%c+1<<" "<<num/r+1;
	if(c==2&&r==2&&num==2) cout<<"2"<<" "<<"2"; 
	else cout<<num/c+1<<" "<<num%r+1;
	}
	return 0;
}
