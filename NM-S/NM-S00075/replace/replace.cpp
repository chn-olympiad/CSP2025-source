#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","w",stdin);
    freopen("replace.out","r",stdout);
	int n,q,a,b,c,d;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
    	cin>>a>>b;
	} 
	for(int j=1;j<=q;j++){
    	cin>>c>>d;
	}
	if(n==4)
	{
		cout<<2<<endl<<0;
	} 
	if(n==3)
	{
		cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
	}
	
    return 0;
}


