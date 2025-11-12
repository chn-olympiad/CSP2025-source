#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],k,s,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+k+1);
	for(int i=1;i<=k;i++){
		if(a[i]==s){
			x=k-i+1;
			break;
		}
	}
	if(x%n==0){
		cout<<x/n<<" "<<n;
	}
	else{
		cout<<x/n+1<<" ";
		if((x/n+1)%2==0)cout<<n-(x-(x/n)*n)+1;
		else cout<<x-(x/n)*n;
	}
	return 0;
}
