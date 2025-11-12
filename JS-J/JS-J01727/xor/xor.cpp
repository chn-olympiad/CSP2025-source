#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],c[20],jsq = 0,r;
struct Bsd{
    int a;
    int b;
}b[100005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        r = a[i];
        if(a[i] == k)
        {
            jsq++;
            b[jsq].a = i;
            b[jsq].b = i;
        }
        for(int j = i;j <= n;j++)
        {
            r = (r ^ a[j]);
            if(r == k)
            {
                jsq++;
                b[jsq].a = i;
                b[jsq].b = j;
                cout << i << ' ' << j << endl;
            }
        }
    }
    for(int i = 1;i <= jsq;i++)
    {
        for(int j = 1;j < i;j++)
        {
            if(b[j].b > b[j + 1].b)
            {
                swap(b[j],b[j + 1]);
            }
        }
    }
    int aa = 0,l = 0;
    for(int i = 1;i <= jsq;i++)
    {
        cout << b[i].a << ' ' << b[i].b << endl;
        if(l < b[i].a)
        {
            l = b[i].b;
            aa++;

        }

    }
    cout << aa;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
