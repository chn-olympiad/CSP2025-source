#include <iostream>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	int a[200005];
	
	cin >> n >> k;
	for(int i = 1; i<=n; i++)
	{
		cin >> a[i];
	}
	int head = 1,tail = 1,ans = 0,cnt = 0;
	while(head <= n)
	{
		if(head == tail) cnt += a[tail];
		else
		{
			if(cnt == a[tail]) cnt = 0;
			else cnt = 1;
		}
		if(cnt == k)
		{
			cnt = 0;
			head = tail+1;
			tail = head;
			ans++;
		}
		else 
		{
			if(tail+1<=n) tail++;
			else
			{
				head++;
				tail = head;
			}
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
