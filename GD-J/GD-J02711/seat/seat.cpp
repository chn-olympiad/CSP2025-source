#include<bits/stdc++.h>
using namespace std;

int n,m,sum;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a=n*m;
	int s[a],b;
	cin>>b;
	s[0]=b;
	for(int i=1;i<a;i++){
		cin>>s[i];
	}
	sort(s,s+a);
	for(int i=0;i<a;i++){
		if(s[i]==b){
			sum=a-i;
			break;
		}
	}
	int c,r;
	if(sum%n==0) c=sum/n;
	else c=sum/n+1;
	if(c%2==1){
		r=sum-n*(c-1);
	}else{
		r=n-(sum-n*(c-1))+1;
	}
	cout<<c<<" "<<r;
	return 0;
} 
