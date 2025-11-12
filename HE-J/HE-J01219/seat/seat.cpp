#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[105];
	cin>>n>>m;
	int a1;
	cin>>a1;
	a[1]=a1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	int pm;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			pm=n*m-i+1;
		}
	}
	int n1,m1;
	if(pm%n==0){
		m1=pm/n;
	
		if(m1%2==0){
			n1=1;
		}
		else{
			n1=n;
		}
		cout<<m1<<" "<<n1;
		return 0;
	}
	else{
		m1=pm/n+1;
		if(m%2==0){
			n1=n-pm%n+1;
		}
		else{
			n1=pm%n;
		}
		cout<<m1<<" "<<n1;
	}
	return 0;
}
