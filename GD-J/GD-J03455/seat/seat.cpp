#include<bits/stdc++.h>
using namespace std;
int a[102];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R=0;
	cin>>n>>m;
    cin>>R;
    int t,ans=1;
	for(int i=1;i<n*m;i++){
		cin>>t;
		if(t>R){
			ans++;
		}
	}
	cout<<(ans+n-1)/n<<' ';
	if(((ans+n-1)/n)%2==0){
		if(ans%n==0){
			cout<<0;
		}else{
			cout<<n-(ans%n)+1;
		}
	}else{
		if(ans%n==0){
			cout<<n;
		}else{
			cout<<ans%n;
		}
	}
	return 0;
} 
