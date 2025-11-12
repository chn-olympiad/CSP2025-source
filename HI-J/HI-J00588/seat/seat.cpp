#include<bits/stdc++.h>
using namespace std;
long long n,x,y,z,sum,nam=0,a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seart.out","w",stdout);
	cin>>x>>y;
	cin>>sum;
	for(int i=1;i<=x;i++){
		for(int j=2;j<=y;j++){
			cin>>n;
			if(n>=sum){
				nam++;
			}
		}
	}
	z=nam/y;
	if(z%2==0){
		a=z+1;
		nam=nam-z*y+1;
		cout<<a<<" "<<nam; 
	}else if(z%2!=0){
		a=z+1;
		nam=nam;
		cout<<a<<" "<<nam; 
	}
	return 0;
}
