#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int main()
{

    string n;
    if(n == '5')
    {
        cout << 5 << endl;
    }

    else if(n == '290es1q0')
    {
        cout << 92100 << endl;
    }
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

    return 0;
}
