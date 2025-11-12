#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[10009],fd,q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>fd;
	a[1]=fd;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=1;i<=m*n;i++){
		if(a[i]==fd){
			fd=i;
		}
	}
	if(fd%n==0){
		q=fd/n;
		cout<<q<<" ";
		if(q%2==0){
			cout<<1;
		}
		else{
			cout<<n;
		}
	}
	else{
		q=fd/n+1;
		cout<<q<<" ";
		if(q%2==0){
			cout<<n-(fd-n*(q-1))+1;
		}
		else{
			cout<<fd-n*(q-1);
		}
	}
	fclose(stdin);
	fclose(stdout);
}
