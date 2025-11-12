#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;cin>>str;
	for(char i:str)
	{
		if(i>='0'&&i<='9') a.push(i);
	}
	while(!a.empty())
	{
		cout<<((char)a.top());
		a.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
