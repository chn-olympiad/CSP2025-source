#include<bits/stdc++.h>

using namespace std;

int n,q,cnt;
string stn1[100010],stn2[100010],stq1[100010],stq2[100010];

bool check(int n,int q)
{
    string st = stq1[q];
    int p = st.find(stn1[n]);
    if(p == -1) return false;
    for(int i = p,j = 0; j < stn1[n].size(); j++,i++)
        st[i] = stn2[n][j];
    if(st.compare(stq2[q]) == 0)
        return true;
    else
        return false;
}

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i = 1; i <= n; i++)
    {
        cin >> stn1[i] >> stn2[i];
    }
    for(int i = 1; i <= q; i++)
    {
        cin >> stq1[i] >> stq2[i];
        cnt = 0;
        for(int j = 1; j <= n; j++)
        {
            if(check(j,i))
            {
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
