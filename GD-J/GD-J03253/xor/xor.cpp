#include <iostream>
using namespace std;

int a[500010],b[500010],c[500010];
int sa[500010];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    bool flag=true,flag2=true;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        if(a[i]!=1)
        {
            flag=false;
            if(a[i]!=0)
            {
                flag2=false;
            }
        }
    }
    if(flag)
    {
        cout << n/2 << endl;
    }
    return 0;
}

