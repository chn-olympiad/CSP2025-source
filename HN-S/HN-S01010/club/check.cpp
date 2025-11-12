#include<bits/stdc++.h>

using namespace std;

int x,y;

int main(){
	ifstream cin1("club.out");
	ifstream cin2("club5.ans");
	while(cin1>>x){
		cin2>>y;
		if(x!=y){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<1;
	return 0; 
}
