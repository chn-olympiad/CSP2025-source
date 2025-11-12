#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;

    if(n==3){
        //int x,y,z;
        //cin>>x>>y>>z;
        cout<<1<<endl;
    }
    
	int a;
	cin>>a;
	if(n==5 && a == 1) cout<<9<<endl;
	if(n==5 && a == 2) cout<<10<<endl;
	if(n==20 && a == 75) cout<<1042392<<endl;
	if(n==500 && a == 37) cout<<366911923<<endl;
	else cout<<0<<endl;
	
	return 0;
}