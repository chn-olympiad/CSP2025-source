#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long a[N],xR,n,m,pm,bs;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xR=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==xR){
			pm=n*m-i+1;
			break;
		}
	}
	if(pm%n==0)
		bs=pm/n;
	else
		bs=pm/n+1;
	if(bs%2==1 && pm%n!=0){
		cout<<bs<<" "<<pm%n<<endl;
	}else if(bs%2==1 && pm%n==0){
		cout<<bs<<" "<<n<<endl;
	}else if(pm%n!=0){
		cout<<bs<<" "<<n-pm%n+1<<endl;
	}else{
		cout<<bs<<" "<<1<<endl;
	}
	return 0;
} 
