#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

short Max(vector<short> a){
	int b=-1;
	for(int i=0;i<a.size();i++){
		if(a[i]>=b && a[i]>=a[a.size()-1]){
			b=a[i];
			a.erase(a.begin()+i);
			a.push_back(b);
		}
	}
	return b;
}
int main(){
	vector<char> a;
	char input = '*';
	while(input != '\r'){
		input = getch();
		cout<<input;
		a.push_back(input);
	}
	system("cls");
	vector<short> b;
	for(char i='0';i<='9';i++){
		for(int q=0;q<a.size();q++){
			if(a[q] == i){
				b.push_back(int(a[q])-48);
			}
		}
	}
	int c=b.size()-1;
	for(int i=0;i<=b.end()-b.begin()+c;i++){
		cout<<Max(b);
		b.pop_back();
	}
	return 0;
}
