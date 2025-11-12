#include <bits/stdc++.h>
using namespace std;

priority_queue<int> q;
int n , m , x , y;

int main(){
	freopen("seat.in" , "r" , "stdin");
	freopen("seat.out" , "w" , "stdout");
	
	cin >> n >> m >> x;
	for (int i = 2 ; i <= n * m ; i++)
	{
		cin >> y;
		q.push(y);		
	}
	q.push(x);
	for (int i = 1 ; i <= n ; i++)
	{
		if (n % 2)
			for (int j = 1 ; j <= m ; j++)
			{
				if (q.top() == x)
					cout << i << ' ' << j;
				q.pop();
			}
		else
			for (int j = m ; j >= 1 ; j--)
			{
				if (q.top() == x)
					cout << i << ' ' << j;
				q.pop();
			}
	}
	
	fclose(stdin);	
	fclose(stdout);
	return 0;
} 
