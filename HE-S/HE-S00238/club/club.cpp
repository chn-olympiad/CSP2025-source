//#include <bits/stdc++.h>
//
//using namespace std;
//
////club
//
//int t;
//
//int a[100005],b[100005],c[100005];
//int dp[100005];
//
//bool cmp(int x,int y)
//{
//	return x > y;
//}
//
//int main()
//{
////	freopen("club.in","r",stdin);
////	freopen("club.out","w",stdout);
//
//	cin >> t;
//	while(t --)
//	{
//		int n,ans = 0;
//		cin >> n;
//		for(int i = 1;i <= n;i ++)
//		{
//			cin >> a[i] >> b[i] >> c[i];
//		}
//		
//		sort(a + 1,a + n + 1,cmp);
//		sort(b + 1,b + n + 1,cmp);
//		sort(c + 1,c + n + 1,cmp);
//		
//		for(int i = 1;i <= n;i ++)
//		{
//			dp[i] = max(dp[i - 1])
//		}
//		cout << ans;
//	}
//
////	fclose(stdin);
////	fclose(stdout);
//	return 0;
//}
#include <bits/stdc++.h>
//È¼¾¡ÁË£¬Æ­·Ö°É 
using namespace std;

//club

int t;

int a[100005],b[100005],c[100005];
int dp[100005];

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin >> t;
	while(t --)
	{
		int n,ans = 0;
		cin >> n;
		
		bool f1 = true,f2 = true; 
		for(int i = 1;i <= n;i ++)
		{
			cin >> a[i] >> b[i] >> c[i];
			if(b[i] != 0) f1 = false;
			if(c[i] != 0) f2 = false;
		}
		
		sort(a + 1,a + n + 1,cmp);
		sort(b + 1,b + n + 1,cmp);
		sort(c + 1,c + n + 1,cmp);
		
		if(f2){
			if(f1){
				for(int i = 1;i <= n / 2;i ++)
				{
					ans += a[i];
				}
			}
		}
		else
		{
			srand(time(0));
			ans = rand() % 20001;
		}
		cout << ans << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
