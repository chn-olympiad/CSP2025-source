#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
struct tNode
{
    int score,id;
}a[200];
bool cmp(tNode a,tNode b)
{
    return a.score>b.score;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n*m;i++)
    {
        cin >> a[i].score;
        a[i].id=i;
    }
    sort(a+1,a+1+n*m,cmp);
    for (int i=1;i<=n*m;i++)
    {
        if (a[i].id==1)
        {
            int l=i/n;
            if (i%n!=0)
            {
                l++;
            }
            if (l%2==1)
            {
                cout << l << " ";
                if (i%n!=0)
                {
                    cout << i%n <<endl;
                }
                else
                {
                    cout << n <<endl;
                }
            }
            else
            {
                cout << l << " ";
                if (i%n!=0)
                {
                    cout << n-i%n <<endl;
                }
                else
                {
                    cout << 1 <<endl;
                }
            }
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
