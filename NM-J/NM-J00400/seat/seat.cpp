#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

	int a[1000];
	int n,m;
	cin>>n>>m;
	int b;
	cin>>a[0];
	b=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	int t=n*m;
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++){
		if(a[i]==b){
		    b=i+1;
		    break;
		}
	}
	int n1,m1;
	if(b%n==0){
		n1=b/n;
		if(n1%2==0){
			m1=1;
		}else{
			m1=n;
		}
	}else{
		n1=b/n+1;
		if(n1%2==0){
			m1=n-(b%n)+1;
		}else{
			m1=b%n;
		}
	}
	cout<<n1<<" "<<m1;
	return 0;
}
