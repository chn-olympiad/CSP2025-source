#include<bits/stdc++.h>
using namespace std;
struct point
{
    int a;
};
point s[10000];
bool cmp(int a,int b)
{
    return a>b;
}
int a[1000005];
int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n;
    int sum = 0;
    cin >> n;
    cout << n;

    /*s[1].a = n;
    for(int i = 1;i <= 100005;i++)
    {
        if(s[i].a == 1 && s[i].a<=9)
        {
            a[i] = s[i].a;
            sum++;
            continue;
        }
        if(s[i].a == 2 && s[i].a<=9)
        {
            a[i] = s[i].a;
            sum++;
            continue;
        }
        if(s[i].a == 3 && s[i].a<=9)
        {
            a[i] = s[i].a;
            sum++;
            continue;
        }
        if(s[i].a == 4 && s[i].a<=9)
        {
            a[i] = s[i].a;
            sum++;
            continue;
        }
        if(s[i].a == 5 && s[i].a<=9)
        {
            a[i] = s[i].a;
            sum++;
            continue;
        }
        if(s[i].a == 6 && s[i].a<=9)
        {
            a[i] = s[i].a;
            sum++;
            continue;
        }
        if(s[i].a == 7 && s[i].a<=9)
        {
            a[i] = s[i].a;
            sum++;
            continue;
        }
        if(s[i].a == 8 && s[i].a<=9)
        {
            a[i] = s[i].a;
            sum++;
            continue;
        }
        if(s[i].a == 9 && s[i].a<=9)
        {
            a[i] = s[i].a;
            sum++;
            continue;
        }
        if(s[i].a == 0 && s[i].a<=9)
        {
            a[i] = s[i].a;
            sum++;
            continue;
        }
    sort(a+1,a+i+1,cmp);

        cout << a[i] << " "<< sum << '\n';
    }

    for(int i = 1;i<=sum;i++)
    {
        cout << a[i];
    }
    */
    return 0;
}
