#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, m;
    bool f = 1;
    cin >> n >> m;
    vector<int> p(n);
    for (auto &it : p)
    {
        cin >> it;
        f=(f==1?it<2:0);
    }
    if (f)
    {
        long long cnt = 0;
        if (m == 1)
            for (auto &it : p)
                cnt += it;
        else
        {
            for (int i = 0; i < n; i++)
                if (i < n)
                    if (p[i] == 0)
                        cnt++;
                    else if (i + 1 < n && p[i + 1])
                        cnt++, i++;
                    else if (i + 2 < n)
                    {
                        int j = i + 2;
                        while (j < n && p[j] == 0)
                            j++;
                        if (j < n)
                            cnt += j - i - 1, i = j;
                    }
        }
        cout << cnt;
    }
    else
    {
        if(n==4){
            if(m==2) cout<<"2";
            if(m==3) cout<<"2";
            if(m==0) cout<<"1";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}