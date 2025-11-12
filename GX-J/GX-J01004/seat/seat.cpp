#include <iostream>

using namespace std;

int main()
{
    int n,m,a[101],s=0;
    int c=1,r=1;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
		cin>>a[i];
    }
    
    for(int i=1;i<n*m;i++){
		if(a[i]>a[0]){
		s=s+1;
		}
		if(r>m){
			c=c+1;
		}
		else{
			r=r+1;
		}
		}
    
    
    cout<<c<<" "<<r;
    return 0;
	}
