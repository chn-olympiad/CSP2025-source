//I'm Tired!
//but I found the T3 looks like a simple greedy
//maybe.
//rp+=inf!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//then i also find we could use qianzhuihe,it's fun
//these words again, CCF is too water.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll sum[500005],a[500005];
int main()
{
    //wait, I'm writing T3?!
    //I'm stronger than one year before!!!
    //last year:40+10+8+0=58
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    int rp = 0;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
        sum[i]+sum[i-1]^a[i];
        if(a[i])rp++;
    }
    //10:20 AFK,I'll rest a while.
    //I'm really TOO TIRED!!!!!!!!!!!!!!1
    //OH my neck.......
    //10:32 back!
    // oh i have no idea:(
    //I'll steal some points first, I can't write the solve:( (P.S.now is 10:53)
    if(k>rp/2)cout << 1;
    else cout << rp/k;
    // this may get 30 pts
    // CCF IS TOO KIND!!!I LOVE CCF!!!!!!!!!!!!!!!!!!!!!!!1
    //11:14 have an idea.
    //may two zhizhen?
    /*
    vector<pair<int,int>> ans;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 0;j<=n;j++)
        {
            if(sum[j]-sum[i]==k)
            {
                ans.push_back(make_pair(j,i));
            }
        }
    }
    bool f[n] = {0};
    sort(ans.begin(),ans.end());
    int res = 0;
    for(auto i:ans)
    {
        if(f[i.first]||f[i.second])continue;
        for(int j = i.second;j<=i.first;j++)f[j]=1;
        res++;
    }
    cout << res;
    */
    //this don't work...
    return 0;
}
/*
sto xsfx orz
sto qjq orz
sto CCF orz
sto CSP orz
I didn't join the S, maybe next year?
RRRRR       PPPPP       +                 +
R    R      P    P      +                 +
RRRRR       PPPPP       +                 +
R R         P           +            +++++++++++
R  R        P    +++++++++++++++          +
R   R       P           +                 +
R    R      P           +                 +
100+100+30+0=230pts
I hope I can get 1=
anyway, I'm a juruo, luogu uid=1210305 welcome to follow me 0w0
*/
