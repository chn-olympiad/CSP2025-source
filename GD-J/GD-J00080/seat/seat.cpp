#include<bits/stdc++.h>
using namespace std;
long long n,m,s=1,t,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=2;i<=n*m;i++){
		cin>>t;
		if(t>r)s++;
	}
	if(s%n==0){
		cout<<s/n<<" ";
		if((s/n)%2==1){
			cout<<n;
		}else{
			cout<<1;
		}
	}else{
		cout<<s/n+1<<" ";
		if((s/n+1)%2==1){
			cout<<s%n;
		}else{
			cout<<n-s%n+1;
		}
	}
	return 0;
}
