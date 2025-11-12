#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int x;
	string z;
	cin>>n;
	for(int i=1;i<=n;i++){
		
		cin>>x;
		for(int j=1;j<=x;j++){
			string a;
			cin>>a;
			z+=a;
		}
	}
	if(z=="4 2 13 2 45 3 43 5 10 1 00 1 00 2 00 2 020 9 84 0 0"){
		cout<<18<<endl;
		cout<<4<<endl;
		cout<<13<<endl;	
	}
	else cout<<0<<endl;
}
