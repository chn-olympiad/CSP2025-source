#include<bits/stdc++.h>
using namespace std;
int n,m,a,p=1,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		cin>>t;
		if(t>a)p++;
	}
	if(p%n==0){
		if((p/n)%2==0) cout<<p/n<<" "<<1;
		else cout<<p/n<<" "<<n;
	}
	else{
		if((p/n+1)%2==0) cout<<p/n+1<<" "<<n-(p%n)+1;
		else cout<<p/n+1<<" "<<p%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

