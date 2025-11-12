#include <bits/stdc++.h>
#define buff ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

const int MAXN = 1e6 + 5;

struct node {
    int num, num2, num3;
    //int n_like;
    int cutn;
    int max_like;
} a[MAXN];
int n;
int ans;
int cnt, cnt2, cnt3;
int cut, max_cutn;

bool cmp(node x, node y)
{
    //if (x.max_like != 1) return y.cutn;
    //if (y.max_like != 1) return x.cutn;
    return x.cutn > y.cutn;
}

void init()
{
    n = 0;
    ans = 0;
    cnt = 0;
    cnt2 = 0;
    cnt3 = 0;
    cut = 0;
    max_cutn = 0;
    for (int i = 1; i <= MAXN; i++)
    {
        a[i].num = 0;
        a[i].num2 = 0;
        a[i].num3 = 0;
        a[i].cutn = 0;
        a[i].max_like = 0;
    }
}
/*
bool cmp(node x, node y)
{
	return x.num > y.num;
}
bool cmp2(node x, node y)
{
	return x.num2 > y.num2;
}
bool cmp3(node x, node y)
{
	return x.num3 > y.num3;
}
*/

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    buff;

    int T;
    cin >> T;
    while (T--)
    {
        init();
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].num >> a[i].num2 >> a[i].num3;
            if (a[i].num > a[i].num2 && a[i].num > a[i].num3)
            {
                cnt++;
                a[i].max_like = 1;
                if (a[i].num2 > a[i].num3)
                {
					//a[i].n_like = 2;
					a[i].cutn = a[i].num - a[i].num2;
                }
                else if (a[i].num2 == a[i].num3)
                {
                    //a[i].n_like = 2;
                    a[i].cutn = a[i].num - a[i].num2;
                }
                else
                {
                    //a[i].n_like = 3;
                    a[i].cutn = a[i].num - a[i].num3;
                }
            }
            if (a[i].num2 > a[i].num && a[i].num2 > a[i].num3)
            {
                cnt2++;
                a[i].max_like = 2;
                if (a[i].num > a[i].num3)
                {
					//a[i].n_like = 1;
					a[i].cutn = a[i].num2 - a[i].num;
                }
                else if (a[i].num == a[i].num3)
                {
                    //a[i].n_like = 1;
                    a[i].cutn = a[i].num2 - a[i].num;
                }
                else
                {
                    //a[i].n_like = 3;
                    a[i].cutn = a[i].num2 - a[i].num3;
                }
            }
            if (a[i].num3 > a[i].num && a[i].num3 > a[i].num2)
            {
                cnt3++;
                a[i].max_like = 3;
                if (a[i].num > a[i].num2)
                {
					//a[i].n_like = 1;
					a[i].cutn = a[i].num3 - a[i].num;
                }
                else if (a[i].num == a[i].num2)
                {
                    //a[i].n_like = 1;
                    a[i].cutn = a[i].num3 - a[i].num;
                }
                else
                {
                    //a[i].n_like = 2;
                    a[i].cutn = a[i].num3 - a[i].num2;
                }
            }
        }

        if (cnt <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2)
        {
            for (int i = 1; i <= n; i++)
            {
                ans += max(a[i].num, max(a[i].num2, a[i].num3));
            }
            cout << ans << endl;
            continue;
        }
        else if (cnt > n / 2)
        {
			cut = cnt - n / 2;
			for (int i = 1; i <= n; i++)
            {
                if (a[i].max_like != 1)
                {
                    a[i].cutn = 0;
                }
            }
			sort(a + 1, a + 1 + n, cmp);
			/*
			for (int i = 1; i <= n / 2; i++)
            {
                max_cutn += a[i].num - a[a[i].n_like].num;
                //a[i].num = 0;
            }
            */
			for (int i = n / 2 + 1; i <= n / 2 + cut; i++)
            {
                //cutn += a[i].num - a[a[i].n_like].num;
                a[i].num = 0;
            }
            for (int i = 1; i <= n; i++)
            {
                //cout << a[i].num << ' ' << a[i].num2 << ' ' << a[i].num3 << endl << "-----" << endl;
                ans += max(a[i].num, max(a[i].num2, a[i].num3));
            }
            cout << ans << endl;
            continue;
		}
		else if (cnt2 > n / 2)
        {
            //cout << T << ' ' << cnt << ' ' << cnt2 << ' ' << cnt3 << ' ' << n / 2 << endl << "-----" << endl;
			cut = cnt2 - n / 2;
			for (int i = 1; i <= n; i++)
            {
                if (a[i].max_like != 2)
                {
                    a[i].cutn = 0;
                }
            }
			sort(a + 1, a + 1 + n, cmp);
			//sort(a + 1, a + 1 + n, cmp2);
			for (int i = n / 2 + 1; i <= n / 2 + cut; i++)
            {
                a[i].num2 = 0;
            }
            /*
            for (int i = 1; i <= n; i++)
            {
                cout << a[i].num << ' ' << a[i].num2 << ' ' << a[i].num3 << endl << "-----" << endl;

            */
            for (int i = 1; i <= n; i++)
            {
                //cout << a[i].num << ' ' << a[i].num2 << ' ' << a[i].num3 << endl << "-----" << endl;
                ans += max(a[i].num, max(a[i].num2, a[i].num3));
            }
            cout << ans << endl;
            continue;
		}
		else if (cnt3 > n / 2)
        {
			cut = cnt3 - n / 2;
			for (int i = 1; i <= n; i++)
            {
                if (a[i].max_like != 3)
                {
                    a[i].cutn = 0;
                }
            }
			sort(a + 1, a + 1 + n, cmp);
			//sort(a + 1, a + 1 + n, cmp3);
			for (int i = n / 2 + 1; i <= n / 2 + cut; i++)
            {
                a[i].num3 = 0;
            }
            for (int i = 1; i <= n; i++)
            {
                //cout << a[i].num << ' ' << a[i].num2 << ' ' << a[i].num3 << endl << "-----" << endl;
                ans += max(a[i].num, max(a[i].num2, a[i].num3));
            }
            cout << ans << endl;
            continue;
		}
    }
    return 0;
}
