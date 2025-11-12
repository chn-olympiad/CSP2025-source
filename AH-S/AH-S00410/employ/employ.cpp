#include<bits/stdc++.h>
using namespace std;
int fun(int n)
{
    if(n==0)return 1;
    int x=1;
    for(int i=1;i<=n;i++){
        x*=i;x%=998244353;
    }return x;
}
int n,m;
bool can[520],outed[520],thinked[520];int p[520];
int outs=0,ined=0;
long long ans;
void dg(int day)
{
    if(ined==m){
        ans+=fun(n+1-day);
        ans%=998244353;
        return;
    }
    if(day>n)return;

    for(int i=1;i<=n;i++){
        if(thinked[i])continue;
        thinked[i]=1;
        if(outs>p[i]){
            outs++;
            dg(day+1);
            outs--;
        }
        else{
            if(can[day]){
                ined++;
                dg(day+1);
                ined--;
            }
            else{
                outs++;
                dg(day+1);
                outs--;
            }
        }
        thinked[i]=0;
    }
    return;
}
int main()
{
    //freopen("employ.in","r",stdin);
    //freopen("employ.out","w",stdout);
    memset(outed,0,sizeof(outed));
    memset(thinked,0,sizeof(thinked));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        if(getchar()=='1')can[i]=1;
        else can[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    dg(1);
    cout<<ans;
    return 0;
}

