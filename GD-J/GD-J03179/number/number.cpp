#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
priority_queue<char> q;
string str;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> str;
	for(char ch : str)
	{
		if(isdigit(ch))
			q.push(ch);
	}
	while(!q.empty())
	{
		cout << q.top();
		q.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
