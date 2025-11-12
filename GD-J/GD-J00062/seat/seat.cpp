#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[150];
int n,m,s,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int R=a[0];
	sort(a,a+n*m);
	reverse(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==R)s=i+1;
	}
	p=s/n;
	if(s%n==0){
		cout<<p<<" ";
		if(p%2==0){
			cout<<"1";
		}else cout<<n; 
	}else{
		cout<<p+1<<" ";
		if((p+1)%2==1){
			cout<<s%n;
		}else{
			cout<<n-s%n+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
