#include <bits/stdc++.h>
using namespace std;
struct Ss{
    int cnt;
    int id;
};
Ss a[300];
int n,m;
bool fanc(Ss x,Ss y)
{
    if(x.cnt>y.cnt) return true;
    return false;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n*m;i++)
    {
        cin >> a[i].cnt;
        a[i].id=i;
    }
    int op=n*m;
    sort(a,a+op,fanc);
    int l,r;
    l=1;
    r=1;
    for(int i=0;i<op;i++)
    {
        //cout << l << " " << r << endl;
        //cout << a[i].cnt << " " << a[i].id << endl;
        if(a[i].id==0)
        {
            cout << l << " " << r << endl;
            return 0;
        }
        else
        {
            if(l%2==1) r++;
            else r--;
            if(r>n||r<1)
            {
                r=1;
                l++;
                if(l%2==0)
                {
                    r=n-r+1;
                }
            }
        }
    }

    return 0;
}