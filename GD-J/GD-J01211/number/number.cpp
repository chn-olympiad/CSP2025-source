#include <bits/stdc++.h>
using namespace std;
string a;
int t[17];
bool tr;

int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" ,stdout);
    cin >> a;
    for(unsigned long long i = 0; i < a.size() ; i++)
    {
        if(a[i] >= '0' and a[i] <= '9')
        {
            t[a[i] - '0'] ++;
        }
    }
    for(int i = 9; i >= 0; i--)
    {
        if(i == 0 and tr == 0)
        {
            printf("0");
            break;
        }
        if(i >= 1 and t[i] != 0)
        {
            tr = 1;
        }
        for(int j = 1; j <= t[i] ; j++)
        {
            printf("%d",i);
        }
    }
    return 0;
}
