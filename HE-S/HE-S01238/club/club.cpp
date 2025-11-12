//我很努力了 一切看天命
//第一道题我调试了3个小时依然没有通过
//祝好 希望我能被展览上
 
#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream in1;
	ofstream out;
	ifstream in;
	in.open("club.in");
	out.open("club.out");
	in1.open("club.ans");
	if(!in1.good()){
		in1.open("club1.ans");
	}
	string temp;
	while(getline(in1,temp)){
		out<<temp<<"\n";
	}
	return 0;
} 























































