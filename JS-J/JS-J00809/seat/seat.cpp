#include<bits/stdc++.h>

using namespace std;

int scores[105];
int seat[15][15];
int mingsc;

int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n , m;

	cin>>n>>m;

	for(int i = 1 ; i <= n * m ; i++)
	{
		cin>>scores[i];
	}

	mingsc = scores[1];

	sort(scores + 1 , scores + 1 + n * m , greater<int>() );

	int rk;
	for(int i = 1 ; i <= n * m ; i++)
	{
		if(scores[i] == mingsc)
		{
			rk = i; 
			break;
		}
	}

	//cerr<<rk;

	int steps = 0;
	for(int i = 1 ; i <= m ; i++)
	{
		//steps++;
		//cerr<<" "<<steps;
		if(i & 1)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				steps++;
				if(steps == rk)
				{
					cout<<i<<" "<<j;
					exit(0);
				}
				
				//cerr<<" "<<steps;
			}
		}
		else
		{
			for(int j = n ; j >= 1 ; j--)
			{
				steps++;
				if(steps == rk)
				{
					cout<<i<<" "<<j;
					exit(0);
				}
				
				//cerr<<" "<<steps;
			}
		}
	}

	// int k = -1;
	// for(int i = 1 ; i <= m ; i++)
	// {
	// 	if(i * n > stnd)
	// 	{
	// 		k = i;
	// 		break;
	// 	}
	// }// int ansm , ansn;
	// ansm = k , ansn = stnd - n * (k - 1);

	// if(k & 1)
	// {
	// 	cout<<m<<" "<<n;
	// }


	return 0;
} 