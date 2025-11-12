#include <bits/stdc++.h>
#define int long long

using namespace std;

int a[100010][4];

vector<int> v[4];

int qwq[100010];

int maxxx(int i)
{
    if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) return 1;
    if(a[i][2] > a[i][1] && a[i][2] > a[i][3]) return 2;
    return 3;
}

int maxx(int i)
{
    return a[i][maxxx(i)];
}

int mid(int j)
{
    bool f[4];
    f[maxxx(j)] = true;
    int maxn = 0;
    for(int i = 1;i <= 3;i++)
    {
        if(!f[i]) maxn = max(maxn,a[j][i]);
    }
    return maxn;
}

int calc()
{
    int sum = 0;
    for(int i = 1;i <= 3;i++)
    {
        for(int j = 0;j < v[i].size();j++)
        {
            sum += maxx(v[i][j]);
//cout <<i <<" " <<j <<endl;
        }
    }
    return sum;
}

void reset()
{
    memset(qwq,0,sizeof(qwq));
    v[1].clear();
    v[2].clear();
    v[3].clear();
    memset(a,0,sizeof(a));
}

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin >> t;
    while(t--)
    {
        reset();

        int n;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i][1] >>a[i][2] >> a[i][3];
        }

        /*
for(int i = 1;i <= n;i++)
cout << a[i][1] << " " <<a[i][2] << " " << a[i][3] <<endl;*/

        for(int i = 1;i <= n;i++)
        {
            v[maxxx(i)].push_back(i);
        }

/*
for(int i = 0;i < v[1].size();i++) cout << v[1][i] << " ";
cout << endl;
for(int i = 0;i < v[2].size();i++) cout << v[2][i] << " ";
cout << endl;
for(int i = 0;i < v[3].size();i++) cout << v[3][i] << " ";
cout << endl;*/

        int sum = calc();
//cout << sum <<endl;
        int now;
        if(v[1].size() > n/2) now = 1;
        else if(v[2].size() > n/2) now = 2;
        else if(v[3].size() > n/2) now = 3;
        else
        {
            cout << sum <<endl;
            continue;
        }

//cout <<now <<endl;
        for(int i = 0;i < v[now].size();i++)
        {
            qwq[i+1] = maxx(v[now][i]) - mid(v[now][i]);
        }

        sort(qwq+1,qwq+v[now].size()+1);

        for(int i = 1;i <= v[now].size() - n/2;i++)
        {
            sum -= qwq[i];
//cout << qwq[i] <<" ";
        }

        cout << sum <<endl;
    }

    return 0;
}
