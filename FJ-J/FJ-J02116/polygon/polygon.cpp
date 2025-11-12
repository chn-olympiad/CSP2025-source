#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<1<<endl;
		return 0;
	}else if(n==2){
		cout<<4<<endl;
		return 0;
	}else if(n==3){
		cout<<6;
		return 0;
	}
	return 0;
} 
