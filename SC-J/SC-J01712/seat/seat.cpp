#include <bits/stdc++.h>
using namespace std;
int a[150];
int n,m;
int q(int w){
	if(w==0){
		return n;
	}
	return w;
}
int w(int f,int e){
	if(f%e==0){
		return f/e;
	}
	return f/e+1;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			s=n*m-i+1;
			break;
		}
	}
	int z=w(s,n);
	if(z%2==1){
		if(s%n==0){
			cout<<s/n<<" "<<q(s%n);
		}else{
			cout<<s/n+1<<" "<<s%n;
		}
	}else{
		if(s%n==0){
			cout<<s/n<<" "<<n-q(s%n)+1;
		}else{
			cout<<s/n+1<<" "<<n-s%n+1;
		}
	}
}