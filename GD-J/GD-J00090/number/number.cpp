#include <iostream>
#include <queue>
using namespace std;
priority_queue<char>a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(char c:s)
		if(isdigit(c))a.push(c);
	while(!a.empty())
		printf("%c",a.top()),a.pop();
	return 0;
} 
