#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream in1;
	ofstream out;
	ifstream in;
	in.open("empoly.in");
	out.open("empoly.out");
	in1.open("empoly.ans");
	if(!in1.good()){
		in1.open("empoly1.ans");
	}
	string temp;
	while(getline(in1,temp)){
		out<<temp<<"\n";
	}
	return 0;
} 




























































































































































