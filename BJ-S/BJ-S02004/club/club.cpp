#include<bits/stdc++.h>
using namespace std;
struct PR
{
    int x,y,z;
};
int read()
{
    int a = 0;
    char ch = getchar();
    while ((ch != ' '&&ch != '\n'))
    {
        a = (a<<3)+(a<<1)+int(ch-'0');
        ch = getchar();
    }
    return a;
}
void out(int a)
{
    stack<int> ot;
    int len = 0;
    while (a)
    {
        ot.push(a % 10);
        a /= 10;
    }
    while(!ot.empty()) putchar(ot.top()+'0'),ot.pop();
    putchar('\n');
}
long long ans[6],cnt[6][3];
bool cmp1(PR a,PR b)
{
    if (a.x != b.x) return a.x > b.x;
    if (a.y != b.y) return a.y > b.y;
    return a.z > b.z;
}
bool cmp2(PR a,PR b)
{
    if (a.x != b.x) return a.x > b.x;
    if (a.z != b.z) return a.z > b.z;
    return a.y > b.y;
}
bool cmp3(PR a,PR b)
{
    if (a.y != b.y) return a.y > b.y;
    if (a.x != b.x) return a.x > b.x;
    return a.z > b.z;
}
bool cmp4(PR a,PR b)
{
    if (a.z != b.z) return a.z > b.z;
    if (a.y != b.y) return a.y > b.y;
    return a.x > b.x;
}
bool cmp5(PR a,PR b)
{
    if (a.z != b.z) return a.z > b.z;
    if (a.x != b.x) return a.x > b.x;
    return a.y > b.y;
}
bool cmp6(PR a,PR b)
{
    if (a.y != b.y) return a.y > b.y;
    if (a.z != b.z) return a.z > b.z;
    return a.x > b.x;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    T = read();
    while(T--)
    {
        int n;
        vector<PR> v[6];
        n = read();
        for (int i = 1;i <= n;i++)
        {
            int t1 = read(),t2 = read(),t3 = read();
            v[0].push_back({t1,t2,t3});
        }
        for (int i = 0;i <= 5;i++) v[i] = v[0],ans[i] = 0,cnt[i][0] = 0,cnt[i][2] = 0,cnt[i][1] = 0;
        sort(v[0].begin(),v[0].end(),cmp1);
        sort(v[1].begin(),v[1].end(),cmp2);
        sort(v[2].begin(),v[2].end(),cmp3);
        sort(v[3].begin(),v[3].end(),cmp4);
        sort(v[4].begin(),v[4].end(),cmp5);
        sort(v[5].begin(),v[5].end(),cmp6);
        for (int i = 0;i < 6;i++)
        {
            for (auto now : v[i])
            {
                if ((now.x >= now.y||cnt[i][1] == n/2)&&(now.x >= now.z||cnt[i][2] == n/2)&&cnt[i][0] < n/2) ++cnt[i][0],ans[i] += now.x;
                else if ((now.y >= now.z||cnt[i][2] == n/2)&&(now.y >= now.x||cnt[i][0] == n/2)&&cnt[i][1] < n/2) ++cnt[i][1],ans[i] += now.y;
                else ++cnt[i][2],ans[i] += now.z;
            }
        }
        out(max(max(max(ans[0],ans[1]),max(ans[2],ans[3])),max(ans[4],ans[5])));
    }
    return 0;
}
