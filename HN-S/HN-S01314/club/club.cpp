#include<iostream>
using namespace std;
int t, n, b1[10005], b2[10005], b3[10005], c1 = 0 , c2, c3;
int main()
{
	freopen("club.in","r"stdin)
	freopen("club.out","w"stdout)
	cin >> t;
	for(int q = 1; q <= t;q++)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> b1[i] >> b2[i] >> b3[i];
		}
		for(int i = 1; i <= n; i++)
		{
			
			if(b1[i] > b2[i]) 
			{
				if(b2[i] > b3[i] ) 
				{
					if(c1 <= n / 2) c1+= b1[i];
					else if(b2[i] > b3[i])
						if(c1 <= n / 2) c2+= b2[i];
					else c3+= b3[i];
				}
				else if(c1 <= n / 2) c2+=b2[i];
				else c3+=b3[i];
			}
			else if(b2[i] > b3[i])
			{
				if(c1 <= n / 2) c2+=b2[i];
				else if(b1[i] > b3[i])
					if(c1 <= n / 2) c1+= b1[i];
				else c3+=b3[i];
			}
			else if(c1 <= n / 2) c3+=b3[i];
			else if(b2[i] > b1[i] ) c2+=b2[i];
			else c1+= b1[i];
			cout << max(max(c1 , c2) , max(c2,c3));
		}
		
	}
	return 0;
}
