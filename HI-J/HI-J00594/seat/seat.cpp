#include<bits/stdc++.h>
using namespace std;
int main(){
	feropen("number.in","r","stdin")
	feropen("number.out","w","stdout")
	int n,m,b,k,q,g=1,o;
	cin>>n>>m;
	b=n*m;
	int a[b];
	for(int i=1;i<=b;i++){
		cin>>a[i];
		o=a[1];
		k++;
		
	}
	for(int i=1;i<=k;i++){
		if(a[i]<a[i+1]){
			q=a[i];
			a[i]=a[i+1];
			a[i+1]=q;
		}
	}
		for(int i=1;i<=k;i++){
		if(a[i]<a[i+1]){
			q=a[i];
			a[i]=a[i+1];
			a[i+1]=q;
		}
	}
		for(int i=1;i<=k;i++){
		if(a[i]<a[i+1]){
			q=a[i];
			a[i]=a[i+1];
			a[i+1]=q;
		}
	}

	for(int i=1;i<=k;i++){
	if(a[i]==o){
		o=i;
		break;
	}
}
	if(n%o!=0 && n>o){//cuowod
		cout<<n/o+o%n<<" ";//m
		if(b%o==0){
		cout<<1;
		}
		if(b%o!=0){cout<<n-b%o;
		}
	}
	if(n%o!=0 && n<o){//cuowod
		cout<<o/n+o%n<<" ";//m
		if(b%o==0){
		cout<<1;
		}
		if(b%o!=0){cout<<b%o;
		}
	}
		if(n%o==0){
		cout<<n/o+1<<" ";
		if(b%o==0){
		cout<<1;
		}
		if(b%o!=0){cout<<n-b%o;
		}
	}
	
	
	
	
	return 0 ;}

