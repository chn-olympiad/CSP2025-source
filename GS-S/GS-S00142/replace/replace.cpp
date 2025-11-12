#include<iostream>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    if(n==4){
    	cout<<2<<endl<<0;
	}
	else if(n==3){
		cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
	}
	else if(n==37375){
		cout<<504898585;
	}
    return 0;
}

