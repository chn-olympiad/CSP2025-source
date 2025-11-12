#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin >> n >> m;
    vector<int> score;
    int ac,se,cnt = 0,r=0,c=1;
    for(int i= 0;i < n*m;i++)
    {
        cin >> ac;
        score.push_back(ac);
    }
    int scoreOfR = score[0];
    sort(score.begin(),score.end(),greater<int>());
    int seat[n+1][m+1] = {0};
    bool flag = true;
    for(int i = 0;i < score.size();i++)
    {
        if(score[i] == scoreOfR)
        {
            se = i+1;
            break;
        }
    }
    while(cnt < se)
    {
        cnt++;
        if(flag)
        {
            r++;
        }
        else
        {
            r--;
        }
        if(r > n)
        {
            r--;
            c++;
            flag = false;
        }
        else if(r <= 0)
        {
            r++;
            c++;
            flag = true;
        }
    }
    cout << c << ' ' << r;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
