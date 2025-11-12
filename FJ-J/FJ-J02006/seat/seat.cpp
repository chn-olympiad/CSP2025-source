#include<bits/stdc++.h>
using namespace std;
int n,m,x,q,p;
bool y,z;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	x=1;
	y=true,z=true;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
	    cin>>a[i];
	    if(a[i]>a[1]) x++;
	    if(y&&a[i]<a[i-1]) y=false;
	    if(z&&a[i]>a[i-1]) z=false;
    }
    if(z){
		cout<<"1 1"<<endl;
		return 0;
	}
    if(y){
    	if(m%2==0) cout<<m<<" 1"<<endl;
    	else cout<<m<<" "<<n<<endl;
    	return 0;
	}
	if(x%n==0)
	{
		q=x/n;
		if(q%2==0) p=1;
		else p=n;
	}
	else
	{
		q=x/n+1;
	    if(q%2==0) p=n+1-x%n;
	    else p=x%n;
	} 
	cout<<q<<" "<<p<<endl;
	return 0;
}