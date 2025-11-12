#include <bits/stdc++.h>
using namespace std;

int arr[10005][3];

struct people
{
    int a, b, c;
}peoples[20005];

bool cmp(people a, people b)
{
    return ((double)max(a.a, max(a.b, a.c))/(a.a+a.b+a.c))>((double)max(b.a, max(b.b, b.c))/(b.a+b.b+b.c));
    //return max(a.a, max(a.b, a.c))>max(b.a, max(b.b, b.c));
}
bool cmp2(people a, people b)
{
    return (a.a+a.b+a.c)>(b.a+b.b+b.c);
}

void test(int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << " a:" << peoples[i].a << " b:" << peoples[i].b << " c:" << peoples[i].c << " sum:" << peoples[i].a + peoples[i].b + peoples[i].c << " max:" << max(peoples[i].a, max(peoples[i].b, peoples[i].c)) << endl;
    }
    cout << endl;
}

void test2(long long ans, int choice, int depth, int popu1, int popu2, int popu3)
{
    cout << " Ans:" << ans << " choice:" << choice <<  " Depth:" << depth << " popu1:" << popu1 << " popu2:" << popu2 << " popu3:" << popu3 << endl;
}

int ann(long long ans, int choice, int depth, int popu1, int popu2, int popu3, int n)
{
	ans+=arr[depth][choice];
	if (popu1 > n/2 || popu2 > n/2 || popu3 > n/2) return -1;
	if (choice == 0) popu1++;
	else if (choice == 1) popu2++;
	else if (choice == 2) popu3++;
	if (depth == n) return ans;
	test2(ans, choice, depth, popu1, popu2, popu3);
	return max(max(ann(ans, 0, depth+1, popu1, popu2, popu3, n), ann(ans, 1, depth+1, popu1, popu2, popu3, n)), ann(ans, 2, depth+1, popu1, popu2, popu3, n));
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	//freopen("D:\\HL-S00434\\club\\club1.in", "r", stdin);
	int t;
	cin >> t;
	while(t--)
	{
	    long long ans = 0;
		int n;
		int popu1 = 0, popu2 = 0, popu3 = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
			peoples[i].a = arr[i][0];
			peoples[i].b = arr[i][1];
			peoples[i].c = arr[i][2];
		}

		if(n <= 10 && false)
		{
			ans = max(max(ann(0, 0, 0, 0, 0, 0, n), ann(0, 1, 0, 0, 0, 0, n)),ann(0, 2, 0, 0, 0, 0, n));
			cout << ans << endl;
			//test(n);
			continue;
		}

        sort(peoples, peoples+n, cmp2);
        sort(peoples, peoples+n, cmp);
        //test only
        //test(n);

        for (int i = 0; i < n; i++)
        {
            if (peoples[i].a >= peoples[i].b && peoples[i].a >= peoples[i].c)
            {
                if (popu1 < n/2)
                {
                    popu1++;
                    ans+=peoples[i].a;
                }
                else if(peoples[i].b >= peoples[i].c)
                {
                    if (popu2 < n/2)
                    {
                        popu2++;
                        ans+=peoples[i].b;
                    }
                    else if (popu3 < n/2)
                    {
                        popu3++;
                        ans+=peoples[i].c;
                    }
                }
            }
            else if (peoples[i].b >= peoples[i].a && peoples[i].b >= peoples[i].c)
            {
                if (popu2 < n/2)
                {
                    popu2++;
                    ans+=peoples[i].b;
                }
                else if(peoples[i].a >= peoples[i].c)
                {
                    if (popu1 < n/2)
                    {
                        popu1++;
                        ans+=peoples[i].a;
                    }
                    else if (popu3 < n/2)
                    {
                        popu3++;
                        ans+=peoples[i].c;
                    }
                }
            }
            else if (peoples[i].c >= peoples[i].a && peoples[i].c >= peoples[i].b)
            {
                if (popu3 < n/2)
                {
                    popu3++;
                    ans+=peoples[i].c;
                }
                else if(peoples[i].a >= peoples[i].b)
                {
                    if (popu1 < n/2)
                    {
                        popu1++;
                        ans+=peoples[i].a;
                    }
                    else if (popu2 < n/2)
                    {
                        popu2++;
                        ans+=peoples[i].b;
                    }
                }
            }
        }
        cout << ans << endl;
	}
	return 0;
}
