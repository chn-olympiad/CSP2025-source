#include<bits/stdc++.h>
using namespace std;
int cj[105];
int main(){
	freopen("airplane.in","r",stdin);
	freopen("airplane.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int w;
	cin>>w;
	for(int i=0;i<n*m-1;i++){
		cin>>cj[i];
	}
	cj[n*m]=w;
	int jh;
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(cj[j]<cj[j+1]){
				jh=cj[j];
				cj[j]=cj[j+1];
				cj[j+1]=jh;
			}
		}
	}
	int g;
	int p=0;
	while(g!=w){
		g=cj[p];
		p+=1;
	}
	if(p%n!=0){
		if(p<=n){
			if(p/n%2!=0){
				if(p/n==0){
					cout<<p/n<<" ";
				}
				else{
					cout<<p/n+1<<" ";
				}
				if(p=n){
					cout<<p/m+2;
				}
				else{
					cout<<p/m+1;
				}
					
		
				}
			else{
				cout<<n-(p/m)+1;
			}			
		}
	
	}


	return 0;	
} 
