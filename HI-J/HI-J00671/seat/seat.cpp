#include<bits/stdc++.h>
using namespace std;
int main( ){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,s1;
	cin>>n>>m;
	cin>>s1; for(int i=0;i<n*m-1;i++){
	cin>>s;
		if(s1>s&&n*m==1){
			cout<<"1 1";
			break;
		}
		else if(s1<s){
			cout<<"1"<<" "<<1+1;
		}
}
	return 0;

