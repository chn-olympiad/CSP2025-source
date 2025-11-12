#include <bits/stdc++.h>
using namespace std;

int n,m;
int Rscore;
int a[1000];
int b = 1;
int I = 1,J = 1;
bool cmp(int The_First_Number,int The_Next_Number)
{
    return(The_First_Number > The_Next_Number);
}

void Do()
{
    if((b == 1 && I == n) || (b == -1 && I == 1))
    {
        J++;
        b = -b;
        return;
    }
    I += b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n * m;i++)
    {
        cin >> a[i];
    }
    Rscore = a[0];
    sort(a,a + n * m,cmp);
    for(int k = 0;k < n * m;k++)
    {
        if(a[k] == Rscore)
        {
            cout << J << ' ' << I;
            return 0;
        }
        Do();
    }
    return 0;
}
