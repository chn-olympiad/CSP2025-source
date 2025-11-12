#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+x+1);
	for(int i=1;i<=x;i++){
		if(a[i]==k){
			k=x-i+1;
			break;
		}
	}
	int n1=0,m1=0;
	if(k%n!=0){
		m1=k/n+1;
		n1=k-(m1-1)*n;
		if(m1%2==1) n1=n1;
		else n1=n-n1+1;
		cout<<m1<<" "<<n1;
	}
	else{
		m1=k/n;
		if(m1%2==1) n1=n;
		else n1=1;
		cout<<m1<<" "<<n1;
	}
	return 0;
}
