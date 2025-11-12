#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1010],b,c;
int main(){
	freopen("seat.cpp","r",stdin);
	freopen("seat.cpp","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m);
	for (int i=1;i<=n*m;i++){
		if(a[i]==b)	c=i;
	}	
	if (c==1)	cout<<"1 1";
	else if(c%2==1){
		if(((c+1)/n)%2==1){
			cout<<((c+1)/n)<<' '<<1;
		}else{
			cout<<((c+1)/n)<<' '<<2;
		}
	}
	else if(c%2==0){
		if(((c+1)/n)%2==1){
			cout<<((c+1)/n)<<' '<<2;
		}else{
			cout<<((c+1)/n)<<' '<<1;
		}
	}
	return 0;
} 
