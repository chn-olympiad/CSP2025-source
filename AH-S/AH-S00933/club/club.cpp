#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1e6+5;

ll T;
ll n;

struct newp
{
    int fora,forb,forc;
}p[maxn];
int ans;
int b[maxn];
void dfs(int dep)
{
    if(dep > n)
    {
        int cnt_a = 0;
        int cnt_b = 0;
        int cnt_c = 0;
        int sum = 0;
        for(int i = 1;i <= n;i++)
        {
            if(b[i] == 1){
                cnt_a++;
                sum += p[i].fora;
            }
            if(b[i] == 2){
                cnt_b++;
                sum += p[i].forb;
            }
            if(b[i] == 3){
                cnt_c++;
                sum += p[i].forc;
            }
            if(cnt_a > n/2)
                return;
            if(cnt_b > n/2)
                return;
            if(cnt_c > n/2)
                return;
        }
        
        ans = max(ans,sum);
        return;
    }
    for(int i = 1;i <= 3;i++)
    {
        b[dep] = i;
        dfs(dep + 1);
    }
}
bool special_task_A = 1;
bool special_task_B = 1;
void reset()
{
    n = ans = 0;
    memset(b,0,sizeof(b));
    special_task_A = 1;
}

void init()
{
    reset();
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> p[i].fora >> p[i].forb >> p[i].forc;  
        if(!(p[i].forb == 0 && p[i].forc == 0))
        {
            special_task_A = 0;
        }
        if(!p[i].forc)
        {
            special_task_B = 1;
        }
    }
}

bool taskAcmp(newp p1,newp p2)
{
    return p1.fora > p2.forb;
}

void work()
{
    const int MAX_PEOPLE = n / 2;
    if(special_task_A)
    {
        sort(p+1,p+1+n,taskAcmp);
        ans = 0;
        for(int i = 1;i <= MAX_PEOPLE;i++)
        {
            ans += p[i].fora;
        }
    }else{
        dfs(1);
    }
    cout << ans << endl;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--)
    {
        init();
        work();
    }
    return 0;
}