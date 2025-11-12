#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
vector<int> a;
bool cmp(int nn, int mm)
{
	return nn > mm;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int R;
	for(int i = 1; i <= n * m; i++)
	{
		int t;
		cin >> t;
		if(i == 1)
		    R = t;
		a.push_back(t);
	}
	sort(a.begin(), a.end(), cmp);
	int ind = find(a.begin(), a.end(), R) - a.begin() + 1;
	for(int i = 1; i <= m; i++)
    {
        if(i % 2 == 1)
        {
            for(int j = 1; j <= n; j++)
            {

                ind--;
                if(ind == 0)
                {
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
        else
        {

            for(int j = n; j >= 1; j--)
            {
                ind--;
                if(ind == 0)
                {
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }
	return 0;
}
