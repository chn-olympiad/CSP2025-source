#include <bits/stdc++.h>
using namespace std ;
int n , a[100005][4] , t ;
long long sum ;
int cnt[4];
bool b;
priority_queue<long long>q ;
void kk(int s)
{
	for(int i = 1 ; i <= 3 ; i++)
	{
		cnt[i]++;
		if(cnt[i] > n / 2)
		{
			cnt[i]-- ;
			return;
		}
		sum += a[s][i] ;
		//cout << a[s][i] << " " << s << " " << i << " " << sum  << endl ;
		if(s == n) 
		{
			q.push(sum) ;
			cnt[i]--;
			sum -= a[s][i] ;
			s--;
			return ;
		}
		kk(++s) ;
		sum -= a[s][i] ;
		cnt[i]--;
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	b = true ;
	cin >> t ;
	while(t--)
	{
		while(!q.empty())
		{
			q.pop();
		}
		b = true ;
		sum = 0 ;
		cin >> n ;
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3] ;
			if(a[i][2] != a[i][3]) b = false ;
		}
		int num = 0 ;
		if(b) 
		{
			for(int i = 1 ; i <= n ; i++)
			{
				q.push(a[i][1]) ;
			}
			while(n != n / 2) 
			{
				sum += q.top() ;
				q.pop() ;
				num++;
			}
			cout << sum ;
			return 0 ;
		}
		kk(1) ;
		cout << q.top() << endl ;
		//cout << "___1" << endl ;
	}
	return 0 ;
}
