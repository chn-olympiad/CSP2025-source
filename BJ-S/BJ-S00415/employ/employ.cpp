#include<bits/stdc++.h>
using namespace std;
int n, m;
string s;
int c[100005];
int a[100005];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    s = " " + s;
    for(int i = 1;i <= n;i++)
    {
        cin >> c[i];
    }
    //if(n<=10)
    //{
        int cnt = 0;
        for(int i = 1;i <= n;i++) a[i] = i;
        do
        {
            //for(int i = 1;i <= n;i++) cout << a[i] << " ";
            //cout << "\n";
            int giveup = 0;
            for(int i = 1;i <= n;i++)
            {
                if(s[i]=='0'||giveup>=c[a[i]]) giveup++;
            }
            if(giveup <= n-m) cnt++;
        }while(next_permutation(a+1, a+n+1));
        cout << cnt;
        //return 0;
    //}

    return 0;
}
