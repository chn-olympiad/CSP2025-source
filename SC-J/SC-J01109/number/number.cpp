#include <bits/stdc++.h>
using namespace std;

int a[10],max1,ans;
int main()
{
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
	string a;
	cin>> a;
	for(int i = 0;i <= a.size();i++)
	{
		if(a[i] = "1"||"2"||"3"||"4"||"5"||"6"||"7"||"8"||"9")
		{
			max1 = a[i];
			ans = max1;
		}
		else
	    {
	    	if(a[i+1] > a[i])
	    	{
	    		max1 = a[i+1];
	    		ans = max1 + a[i];
			}
			
		}
	}
	cout << max1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
