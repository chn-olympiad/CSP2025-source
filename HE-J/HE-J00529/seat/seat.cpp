#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    cin>>a[n*m];
    int r=1,c=1;
    for(int i=0;i<=n*m;i++){
    	int a[i];
    	if(a[i]>=a[1]){
    		r+=r;
    		if(r=n)
    		{
    			c+=c;
    			break; 
			}

		}
}
cout<<r<<" "<<c<<endl;

	
	return 0;
}

