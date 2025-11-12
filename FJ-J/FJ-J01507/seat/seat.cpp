#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b[110],ans=1,y=0,z=0,max,c,r1,r2;
	cin>>n>>m;  
	for(int x=1;x<=n*m;x++){
		cin>>b[x];
		max=b[1];
		if(b[x]>max) ans++;
	}
	z=ans/m;
	y=ans-(z*m);
	c=z+1;
	r1=y;
	r2=n+1-y;
	if(ans<=n) cout<<"1 "<<ans;
    else {
    	if(z+1%2==1)
			cout<<c<<" "<<r1;
		else
            cout<<c<<" "<<r2;
	}
    return 0;
}