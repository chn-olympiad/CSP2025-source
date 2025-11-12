#include<bits/stdc++.h>
using namespace std;
int x[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>x[i];
	}
	if(a==3){
		
		if(max(max(x[0],x[1]),x[2])*2<x[0]+x[1]+x[2]){
			cout<<"1";
		}else{
			cout<<"0";
		}
		return 0;
	}else{
		sort(x,x+a);
		if(x[a-1]==1){
			cout<<((a-1)*(a-2))/2;
			return 0;
		}
	}
	return 0;
}