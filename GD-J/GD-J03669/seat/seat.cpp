#include<bits/stdc++.h>
using namespace std;
long long a[10000001],m,n,l,t,h,k,s,s1;
int main(){
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)cin>>a[i];
	l=a[1];
	sort(a+1,a+m*n+1,greater<int>());
	for(int i=1;i<=m*n;i++){
		if(a[i]==l){
			t=i;
			break;
		}
	}
	if(t>=2*n){
		s=t/(2*n);
		s1=t-s*2*n;
		if(s1/n==1){
			h=2*s+1;
			k=2*n-s1+1;
		}
		else{
			h=2*s;
			k=s1;
		}
	}
	else{
		s=t/n;
		s1=t%n;
		if(s==0){
			h=1;
			k=s1;
		}
		else{
			if(t==n){
				h=1;
				k=n;
			}
			else{
				h=2;
				k=n-s1+1;
			}
		}
		
	}
	cout<<h<<" "<<k;
}
