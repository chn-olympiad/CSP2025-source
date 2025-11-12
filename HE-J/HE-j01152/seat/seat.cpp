#include <bits/stdc++.h>
using namespace std;
int n,m,num;
const int N = 15;
int a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i = n;i++)
    {
        cin >> a[i];
        for(int j = 1;j <= m;j++)
        {
           if(a[i].max)
           {
               sort(a[i],a[i] + 1);
               num++;
           }
           if(num == a[i] && num == a[j])
           {
               n += a[i];
               m += a[j];
               num ++;
               n -= num;
               m -= num;
           }
        }
    }
    cout << n << " "<< m;
	return 0;
}
