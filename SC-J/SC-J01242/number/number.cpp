#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> n;
bool compare(char a,char b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a=0,sl=s.length();
	for(int i=0;i<sl;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n.push_back(s[i]);
			a++;
		}
	}
	sort(n.begin(),n.end(),compare);
	for(int i=0;i<a;i++){
		cout<<n[i];
	}cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}