#include<bits/stdc++.h>
using namespace std;
int n,m,sum,ap,sa;int a[11110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	cin>>ap;
	a[1]=ap;
	for(int i=2;i<=sum;i++){
		cin>>a[i];
	}
	sort(a+1,a+sum+1);
	for(int i=1;i<=sum;i++){
		if(a[i]==ap){
			sa=sum-i+1;
			break;
		}
	}
	if(sa%n!=0){
		cout<<(int)(sa/n+1)<<' ';
	}else{
		cout<<(int)(sa/n)<<' ';
	}
	
	sa=sa%(2*n);
	if(sa==0){
		sa=2*n;
	}
	if(sa>n){
		cout<<2*n-sa+1<<endl;
	}else{
		cout<<sa<<endl;
	}
	return 0;
}