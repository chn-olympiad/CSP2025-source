#include<bits/stdc++.h>
#include<fstream>
using namespace std;
string s[21];
int main(){
	ifstream("seat.in");
	ofstream("seat.out");
	int n,m,a;
	cin>>n>>m>>a;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
		if(s[i]==a){
			s[i]++;
		}
	}
	return 0;
}