#include <iostream>
using namespace std;

int n,sum = 0,cnt = 0;
int a[5005];  

//void dfs(int k) 
//{
//	
//}

int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","u",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
//	for(int i = 3;i <= n;i++)
//	{
//		dfs(i);
//		sum += cnt;
//		cnt = 0;
//	}
	cout << sum;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
