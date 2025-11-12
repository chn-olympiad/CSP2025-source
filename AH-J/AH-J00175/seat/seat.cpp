#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a1,a,x=1,s=1;
	cin>>a1;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>a1) x++;
	}
	while(x>0){
		if(x<=2*m){
			if(x<=m){
				cout<<s<<" "<<x<<endl;
				return 0;
			}
			else {
				x-=m;
				cout<<s+1<<" "<<m-x+1<<endl;
				return 0;
			}	
		}
		s+=2;x-=2*m;
	}
    return 0;
}
