#include<bits/stdc++.h>
using namespace std;

int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,c=1,r=1;
	cin>>n>>m;
	int cj=1,z;
	z=cj;
	for(int i=1;i<=m;i++){
			cin>>cj;
			if(cj>z){
			z=cj;
				r++;
				if(r>n){  
					c++;
					r--;  
				}
		}
	}
	cout<<c<<" "<<r<<endl;
	return 0;
} 

