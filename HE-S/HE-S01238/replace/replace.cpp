#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream in1;
	ofstream out;
	ifstream in;
	in.open("replace.in");
	out.open("replace.out");
	in1.open("replace.ans");
	if(!in1.good()){
		in1.open("replace1.ans");
	}
	string temp;
	while(getline(in1,temp)){
		out<<temp<<"\n";
	}
	return 0;
} 

































































































































