#include <iostream>

using namespace std;

long long N,sum = 0;
int sticks[5005];
bool state[5005];

void dfs(int i,int max_stick,int least,int sticks_sum)
{
	if (i == 0)
	{
		if (sticks_sum > max_stick * 2)
		{
			sum++;
			sum = sum % 998244353;
		}
		return;
	}
	else
	{
		for (int j = least; j <= N; ++j)
		{
			if (state[j] == false)
			{
				state[j] = true;
				dfs(i - 1,(sticks[j] > max_stick ? sticks[j] : max_stick),j + 1,sticks_sum + sticks[j]);
				state[j] = false;
			}
		}
	}
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

    cin >> N;

    bool is_all_one = true;
    for (int i = 1; i <= N; ++i)
    {
        cin >> sticks[i];
        if (sticks[i] != 1)
        {
            is_all_one = false;
        }
    }

    if (is_all_one == true)
    {
        for (int i = 3; i <= N; ++i)
        {
            for (int j = 1; j <= N - i + 1; ++j)
            {
                sum = sum + j * (N - i - j + 2);
                sum = sum % 998244353;
            }
        }
        cout << sum;
        return 0;
    }

	for (int i = 3; i <= N; ++i)
	{
		dfs(i,0,1,0);
	}

	cout << sum;
    return 0;
}
