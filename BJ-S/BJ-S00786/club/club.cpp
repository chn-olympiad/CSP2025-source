#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int one;
    int two;
    int thr;
    int diff;
}a[1000001];
int max_mem = 0;
int ans = 0;
int n = 0;
void dfs(int c1,int c2,int c3,int sum,int x){ //three club's member,c1,c2,c3
    if(c1 > max_mem || c2 > max_mem || c3 > max_mem) return;
    if(x == n + 1) {
        ans = max(ans,sum);
        return;
    }
    dfs(c1 + 1,c2,c3,sum + a[x].one,x + 1);
    dfs(c1,c2 + 1,c3,sum + a[x].two,x + 1);
    dfs(c1,c2,c3 + 1,sum + a[x].thr,x + 1);
}
bool cmpa(node x,node y){
    return x.one > y.one;
}
bool cmp(node x,node y){
    return x.diff > y.diff;
}
int diff[100001];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t = 0;
    cin>>t;
    while(t--){
        ans = 0;
        cin>>n;
        bool is_a = 1;
        bool is_b = 1;
        for(int i = 1;i <= n;i++){
            cin>>a[i].one>>a[i].two>>a[i].thr;
            if(a[i].two != 0 || a[i].thr != 0)
            {
                is_a= 0;
            }
            if(a[i].thr != 0) is_b = 0;
        }
        max_mem = n / 2;
        if(is_a){
            sort(a + 1,a + n + 1,cmpa);
            int sum = 0;
            for(int i = 1;i <= max_mem;i++) sum += a[i].one;
            cout<<sum<<endl;
        }
        else if(is_b){ //give me some scores please.... more !!
            for(int i = 1;i <= n;i++){
                a[i].diff = a[i].one - a[i].two;
            }
            sort(a + 1,a + n + 1,cmp);
            ll ans = 0;
            int c1 = 0;
            int c2 = 0;
            for(int i = 1;i <= n;i++){
                if(c1 + 1 > n / 2){
                    c2++;
                    ans += a[i].two;
                    continue;
                }
                if(c2 + 1 > n / 2){
                    c1++;
                    ans += a[i].one;
                    continue;
                }
                if(a[i].diff >= 0 && c1 + 1 <= n / 2)
                {
                    ans += a[i].one;
                    c1++;
                    continue;
                }
                if(a[i].diff <= 0 && c2 + 1 <= n / 2){
                    ans += a[i].two;
                    c2++;
                    continue;
                }
            }
            cout<<ans<<endl;
        }
        else if(n <= 20){

            dfs(0,0,0,0,0);
            cout<<ans<<endl;
        }
    }
    return 0;
}
