#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,x,sum=1;
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		cin>>x;
		if(x>a)sum++;
	}
	if(sum%n==0){
		cout<<sum/n<<" ";
		if((sum/n)%2==0)cout<<1<<endl;
		else cout<<n<<endl;
	}
	else{
		cout<<sum/n+1<<" ";
		if((sum/n)%2==0)cout<<sum%n<<endl;
		else cout<<n-(sum%n)+1<<endl;
	}
	return 0;
}
