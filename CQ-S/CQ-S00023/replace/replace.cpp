#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

struct node
{
    int bf1, bf2;
    int ne1, ne2;
} a[N], q[N];

int main(void)
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q1;
    cin >> n >> q1;
    for (int j = 1; j <= n; j++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int l = s1.size();
        for (int i = 0; i <= l - 1; i++)
        {
            if (s1[i] == 'b')
            {
                a[j].bf1 = i;
                a[j].ne1 = l - i - 1;
            }
            if (s2[i] == 'b')
            {
                a[j].bf2 = i;
                a[j].ne2 = l - i - 1;
            }
        }
        //cout<<a[j].bf1<<" "<<a[j].ne1<<endl;
    }
    for (int j = 1; j <= q1; j++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int l = s1.size();
        for (int i = 0; i <= l - 1; i++)
        {
            if (s1[i] == 'b')
            {
                q[j].bf1 = i;
                q[j].ne1 = l - i - 1;
            }
            if (s2[i] == 'b')
            {
                q[j].bf2 = i;
                q[j].ne2 = l - i - 1;
            }
        }
        //cout<<q[j].bf1<<" "<<q[j].ne1<<endl;
    }
    int ans=0;
    for(int j=1;j<=q1;j++)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(q[j].bf1-a[i].bf1==q[j].bf2-a[i].bf2)
            {
                if(q[j].ne1>=a[i].ne1&&q[j].ne2>=a[i].ne2&&q[j].bf1>=a[i].bf1&&q[j].bf2>=a[i].bf2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
