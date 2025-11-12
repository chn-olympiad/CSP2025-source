#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
int n,a[5025],sum[5025],ans=0;
map<pair<int,int>,pair<int,int> > mp;
void dfs(int id,int cnt,int sum,int mx){
    //cout << id << ' ' << cnt << ' ' << sum << ' ' << mx << endl;
    if(cnt>=3 and sum>2*mx)ans++,ans%=998244353;
    if(id==n)return;
    if(mp[make_pair(id,cnt)]==make_pair(sum+1,mx+1))return;
    mp[make_pair(id,cnt)]=make_pair(sum+1,mx+1);
    fr(i,id+1,n+1){
        dfs(i,cnt+1,sum+a[i],max(a[i],mx));//xuan
        //cout << endl;
        if(id+1!=n)dfs(i,cnt,sum,mx);//bu xuan
    }
}
signed main(){
    cin.tie(0);
    cout.tie(0);
    freopen(stdin,"r","polygon.in");
    freopen(stdout,"w","polygon.out");
    cin >> n;
    fr(i,1,n+1)cin >> a[i];
    dfs(0,0,0,0);
    cout << ans-1;
    return 0;
}
/*
& &
(~)
written by Leon2012
I love CCF!
I'm going to AK CSP-J/S!
*/
