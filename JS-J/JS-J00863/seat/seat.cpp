#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 20;

int n,m;
int pos[N][N];
int a[N * N];
int aa;
int cnt;

bool cmp(int x,int y)
{
    return x > y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i <= n * m;i++)
    {
        cin >> a[i];
    }
    aa = a[1];
    sort(a + 1, a + n*m + 1,cmp);
//    for(int i = 1;i <= n * m;i++)
//    {
//        cout << a[i] <<"  ";
//    }

    for(int j = 1;j <= m;j++)
    {
        if(j % 2 == 1)
        {
            for(int i = 1;i <= n;i++)
            {
                cnt++;
                pos[i][j] = a[cnt];
            }
        }
        else
        {
            for(int i = n;i >= 1;i--)
            {
                cnt++;
                pos[i][j] = a[cnt];
            }
        }
    }

    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
 //           cout << pos[i][j] <<" ";
            if(pos[i][j] == aa)
            {
 //               cout << "ans: ";
                cout << j << " " << i<<endl;
            }
        }
 //       cout <<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
