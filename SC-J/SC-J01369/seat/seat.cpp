#include<bits/stdc++.h>
using namespace std;
int a[1001],t,x,s;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			t=a[1];
		}
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		s++;
		if(a[i]==t)break;
	}
	if(s%n==0){
		cout<<s/n<<" ";
		if(s/n%2==1){
			cout<<n;
		}else{
			cout<<"1";
		}
	}else{
		cout<<s/n+1<<" ";
		if((s/n+1)%2==1)cout<<s%n;
		else cout<<n-s%n+1;
	}
	return 0;
}
