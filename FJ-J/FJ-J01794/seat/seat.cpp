#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,s=1;
int main()
{
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n*m-1;i++){
		cin>>b;
		if(b>a)s++;
	}
	if(s%n==0){
		if(s/n%2==1)cout<<s/n<<" "<<n;
		else cout<<s/n<<" "<<1;
	}
	else{
		if((s/n+1)%2==1)cout<<s/n+1<<" "<<s%n;
		else cout<<s/n+1<<" "<<n-s%n+1;
	}
	return 0;
}