#include<bits/stdc++.h>

using namespace std;


bool cmp(int a,int b)
{
	return a > b; 
}

int main()
{
 	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int arr[105];
	for (int i=1;i<=n*m;i++)
	{
		cin >> arr[i];
	}
	int key = arr[1];
	int key_i = 0;
	sort(arr+1,arr+1+(n*m),cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (arr[i] == key)
		{
			key_i = i;
			break;
		}
	}
	
	int i=1,j=1,sum = 1,sum_y = sum;
	int dj[] = {1,-1,0};//0об 1ио
	int set = 0;
	while (sum < key_i)
	{	
		if (i % 2 == 0) set = 1;
		else if (i %2 != 0) set = 0;
		if (sum - sum_y == m-1)
		{
			i += 1;
			sum_y = sum+1;
			set = 2;	
		}		
		j += dj[set];
		sum += 1;
	}  
	
	cout << i << " " << j;
	return 0;
} 
