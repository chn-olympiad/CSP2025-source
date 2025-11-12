#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],a1=0,s=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+1+(n*m));
	for(int i=n*m;i>=1;i--){
		s++;
		if(a[i]==a1){
			break;
		}	
	}
	if(s%n==0){
		cout<<s/n;
		cout<<" ";
		int j=s/n;
		if(j%2==0){
			cout<<n-n+1;
		}else{
			cout<<n;
		}
	}else{
		cout<<(s/n)+1;
		cout<<" ";
		int j=(s/n)+1;
		if(j%2==0){
			cout<<n-(s%n)+1;
		}else{
			cout<<s%n;
		}
	}
}
