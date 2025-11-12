#include<bits/stdc++.h>
using namespace std;

string s;
priority_queue<int > q;

//48 57
//窝要上迷惑行为大赏！！！
//feropen, number3, numder4
//itn, fro, 但是能押对嘛。。。
//第四题给你们唱《雾鸦》
//这题简单, 但是我要先打了
//I LOVE CCF FOR EVER!!! 
 

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	int sz = s.size();
	
	for(int i = 0; i < sz; i++)
	{
		if(s[i] <= 57 && s[i] >= 48)
		q.push(s[i] - 48);
	}
	
	while(!q.empty())
	{
		printf("%d", q.top());
		q.pop();
	}
	
	return 0;
}
