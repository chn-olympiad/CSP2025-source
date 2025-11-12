#include <bits/stdc++.h>
using namespace std;
int n,m;
void was(int x){
	int sas=(x-1)/n+1;
	cout<<sas<<' ';
	if(sas%2==1){
		cout<<(x+n-1)%n+1;
	}
	else{
		cout<<(n+1-(x+n-1)%n-1);
	}
	return;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	int man,a[105];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
			cin>>a[i*m-m+j];
		}
	}
	man=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==man){
			cout<<i<<endl; 
			was(i);
			 
		}
	}
	
	
	
	cout<<endl;	
	return 0;
}
