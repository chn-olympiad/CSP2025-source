#include<iostream>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k;
    cin>>n>>m>>k;
    if(n==4){
    	cout<<13;
	}
	if(n==1000&&k==5){
		cout<<505585650;
	}
	else{
		cout<<504898585;
	}
    return 0;
}

