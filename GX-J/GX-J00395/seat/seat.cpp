#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdin);
	string b;

	cin>>b;
	int a[b.size()]={0},s=b.size();
	for(int i=0;i<s;i++){
		a[i]+=b[i];
		
	}
	for(int i=0;i<s;i++){
		cout<<a[i]<<endl;
		
	}
	
	return 0;
}
 
