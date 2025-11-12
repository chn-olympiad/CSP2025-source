#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,a_t,s=1;//n行 
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		cin>>a_t;
		if(a_t>a)s++;
	}
	
	
	
	
	
	if((s/n)%2==0){//奇数列 
		if(s%n==0)cout<<s/n<<" "<<1;
		else cout<<s/n+1<<" "<<s%n;
	}else{//偶数列
		if(s%n==0)cout<<s/n<<" "<<n;
		else cout<<s/n+1<<" "<<n-s%n+1;
	}
}
