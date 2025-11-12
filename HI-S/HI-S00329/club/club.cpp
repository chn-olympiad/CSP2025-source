# include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("club.in", "r", stdin);
	
	freopen("club.out", "w", stdout); 
	
	int t;
	
	cin >> t;
	
	while(t--)
	{
		int n;
		
		cin >> n;
		
		vector<int> s1(n);
		
		vector<int> s2(n);
		
		vector<int> s3(n);
		
		for(int i = 0; i < n; i++)
		{
			cin >> s1[i] >> s2[i] >> s3[i];
		}
		
		int sum = 0;
		
		int op, tp, rp;
		
		op = tp = rp = 0;
		
		for(int i = 0; i < n; i++)
		{
			int temp = max(s1[i], max(s2[i], s3[i]));
			
			if(temp == s1[i])
			{
				op++;
			}
			
			else if(temp == s2[i])
			{
				tp++;
			}
			
			else if(temp == s3[i])
			{
				rp++;
			}
			
			sum += temp;
		}
		
		// cout << "first ans is " << sum << endl; 
		
		// cout << op << ' ' << tp << ' ' << rp << endl; 
		
		if(op > n / 2 || tp > n / 2 || rp > n / 2)
		{
			for(int i = 0; i < n; i++)
			{
				int cnt = max(s1[i], max(s2[i], s3[i]));
				
				sum -= cnt;
				
				if(cnt == s1[i])
				{
					op--;
					
					if(s2[i] >= s3[i])
					{
						sum += s2[i];
						
						tp++;
					}
					
					else
					{
						sum += s3[i];
						
						rp++;
					}
				}
				
				else if(cnt == s2[i])
				{
					tp--;
					
					if(s1[i] >= s3[i])
					{
						sum += s1[i];
						
						op++;
					}
					
					else
					{
						sum += s3[i];
						
						rp++;
					}
				}
				
				else if(cnt == s3[i])
				{
					rp--;
					
					if(s2[i] >= s1[i])
					{
						sum += s2[i];
						
						tp++;
					}
					
					else
					{
						sum += s1[i];
						
						op++;
					}
				}
				
				if((op <= n / 2 && tp <= n / 2 && rp <= n / 2))
				{
					break;
				}
			}
			
			cout << sum << endl;
		}
		
		else
		{
			cout << sum << endl;
		}
	}
}
