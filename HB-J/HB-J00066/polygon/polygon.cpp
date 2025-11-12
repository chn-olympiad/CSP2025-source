#include<bits/stdc++.h>
using namespace std;
int n,b[15];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(n==3){
		if(b[1]+b[2]+b[3]>2*max(max(b[1],b[2]),max(b[2],b[3]))){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	if(n<3){
		cout<<"0";
	}
	return 0;
}
