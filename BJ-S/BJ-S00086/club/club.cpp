#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int a[4][20005];
int n;
int nf[25],tt[4],ta=0;
int t;
void n4(int step)
{

    if (step>n)
    {
        t = max(t,ta);
        return;
    }
    for(int i = 1;i <= 3;i++)
    {
        if(tt[i]*2<n)
        {
            nf[step] = i;
            tt[i]++;
            ta+=a[i][step];
            n4(step+1);
            tt[i]--;
            ta-=a[i][step];
        }
    }
}

void f23()
{
    sort(a[1]+1,a[1]+n+1);
    for(int i = n;i>n/2;i--)
    {
        t+=a[1][i];
    }
    cout << t << "\n";
}


void man()
{
    t = 0;
    bool ff2=1,ff3=1;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[1][i] >> a[2][i] >> a[3][i];
        if(a[2][i]>0)ff2=0;
        if(a[3][i]>0)ff3=0;
    }

    if(n<=10)
    {
        memset(tt,0,sizeof(tt));
        ta=0;
        n4(1);
        cout << t << "\n" ;
        return;
    }

    if(ff2&&ff3)
    {
        f23();
        return;
    }

}



int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int ttt;
    cin >> ttt;
    while(ttt--)
    {
        man();
    }
    return 0;
}
