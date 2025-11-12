#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10000]={0},b[10000]={0},k=1;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}               
	int g=a[1];
	sort(a,a+n*m);
	for(int i=n*m;i>=1;i++){
		a[k]=b[i];
		k++;
	}                    
	for(int i=1;i<=m*n;i++){
		if(g==a[i]){
		g=i;
		break;	
		}
	}     
	if(g/n==0){
		cout<<g/n<<" "; 
		if(g/n%2==0)cout<<1;	  
		else cout<<n;		
	}
	else{
	cout<<g/n+1<<" ";
		if((g/n+1)%2==0)cout<<n-g%n+1;	  
		else cout<<g%n;
	}                                                                                            
	return 0;
}