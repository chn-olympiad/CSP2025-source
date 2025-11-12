#include<iostream>
using namespace std;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b,x=1,y=1;
	cin>>n>>m>>b;
	for(int i=0;i<n*m-1;i++){
		int t;
		cin>>t;
		if(t>b){
			int t=y+(x%2>0)-(x%2==0);
			if(t>n||t<1)x++;
			else y=t;
		}
	}
	cout<<x<<" "<<y;
	return 0;
} 
