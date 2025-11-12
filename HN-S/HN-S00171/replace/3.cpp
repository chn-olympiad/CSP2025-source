#include<bits/stdc++.h>
using namespace std;
int cc;
int main(){
	while(++cc){
		system("./2>replace.in"),system("./1<replace.in>1.out"),system("./replace");
		if(system("diff 1.out replace.out -Z")){
			cout<<"Wrong Answer on #"<<cc<<endl;
			return 0;
		}
		cout<<"Accepted #"<<cc<<endl;
	}
	return 0;
}