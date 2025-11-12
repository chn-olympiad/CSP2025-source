#include<bits/stdc++.h> 
using namespace std; 

string a[105];

int main(){ 
	freopen("seat.in","r",stdin); 
	freopen("seat.out","t",stdout); 
	memset(a,0,sizeof(a)); 
	int n,m,it=1; 
	string ite; 
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
		cin>>a[i]; 
	} 
	ite=a[1]; 
	it=101-ite; 
	clog<<it<<endl;  
	cout<<(it-1)%n+1<<' '<<(it-1)/n+1;  
	return 0;
} 
