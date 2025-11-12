#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
struct node{
    LL a,b,c;
}a[100005];
LL t1[100005],t2[100005],t3[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
    	int c1=0,c2=0,c3=0;
    	int n;
    	cin >> n;
    	for (int i = 1;i <= n;i++)
    		cin >> a[i].a >> a[i].b >> a[i].c;
        LL sum = 0;
        for (int i = 1;i <= n;i++)
        {
            LL x = max(a[i].a,max(a[i].b,a[i].c));
            sum += x;
            if (x == a[i].a) 
                t1[++c1] = a[i].a-max(a[i].b,a[i].c);
            else if (x == a[i].b)
            	t2[++c2] = a[i].b-max(a[i].a,a[i].c);
            else t3[++c3] = a[i].c-max(a[i].a,a[i].b);
        }
        if (c1<=n/2 && c2<=n/2 && c3<=n/2)
        {
        	cout << sum << endl;
        	continue;
        }
        if (c1 > n/2)
        {
        	sort(t1+1, t1+c1+1);
        	for (int i = 1;i <= c1-n/2;i++)
        		sum -= t1[i];
        }
        else if (c2 > n/2)
        {
        	sort(t2+1, t2+c2+1);
            for (int i = 1;i <= c2-n/2;i++)
            	sum -= t2[i];
        }
        else
        {
            sort(t3+1, t3+c3+1);
            for (int i = 1;i <= c3-n/2;i++)
            	sum -= t3[i];
        }
        cout << sum << endl;
    }
	return 0;
}