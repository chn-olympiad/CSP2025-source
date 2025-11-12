#include <bits/stdc++.h>
using namespace std;
int a[120];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=1,b,c;
	for(int i=1;i<=n*m;i++){
		if(a[1]>a[i]&&s>1){
			s-=1;
		}if(a[1]<a[i]){
			s+=1;
		}
	}
	if(s%m==0){
	    b=s/m;
	}else{
	    b=s/m+1;
	    }
	if(b%2==0){
		c=n-s%m+1;
	}else{
		c=s%m;
	}
	cout<<b<<" "<<c;
	return 0;
}
