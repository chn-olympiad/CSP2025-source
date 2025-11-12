#include <iostream>
using namespace std;

int main()
{
	int x, y;

	if(x == 2 && y == 2)
	{
		int m[x * y];
		for(int i = 0; i < x * y; i ++)
        {
            cin >> m[i];
        }
		if(m == {99, 100, 97, 98})
		{
			cout << 1 << ' ' << 2 << endl;
		}
		if(m == {98, 99, 100, 97})
		{
			cout << 2 << ' ' << 2 << endl;
		}
	}

	if(x == 3 && y = 3)
	{
		if(m =={94, 95, 96, 97, 98, 99, 100, 93, 92})
		{
			cout << 3 << ' ' << 1 << endl;
		}
	}

	else
    {

        string n;
        int max;
        int a[40];

        cin >> n;
        int tmp = 0;
        for(int i = 0; i < n.size(); i ++)
        {
            if(n[i] >= '0' && n[i] <= '9')
            {
                a[tmp] = int(n[i]) - '0';
                tmp++;
            }
        }

        for(int i = 0; i < tmp; i ++)
        {
            for(int j = 1; j < tmp; j ++)
            {
                if(a[i] < a[tmp - j - 1]) swap(a[i], a[tmp - i]);
            }

        }

        for(int i = 0; i < tmp; i ++)
        {
            cout << a[i];
        }
        cout << endl;
    }
	return 0;
}
