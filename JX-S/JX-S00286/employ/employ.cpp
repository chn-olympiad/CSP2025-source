#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int num[5];
struct activity{
    int idx,val;
}a[N][5];
bool cmp(activity x,activity y){
    return x.val>y.val;
}
void solve(){
    int n;cin>>n;
    int sum=0,limit=n/2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j].val;
            a[i][j].idx=j;
        }
        sort(a[i]+1,a[i]+4,cmp);
        sum+=a[i][1].val;
        num[a[i][1].idx]++;
    }
    if(num[1]<=limit&&num[2]<=limit&&num[3]<=limit){
        cout<<sum<<'\n';
        return ;
    }
    int over,flag;
    if(num[1]>limit){
        over=num[1]-limit;
        flag=1;
    }else if(num[2]>limit){
        over=num[2]-limit;
        flag=2;
    }else if(num[3]>limit){
        over=num[3]-limit;
        flag=3;
    }
    while(over--){
        int reval=-1;
        pair<int,int> reidx;
        for(int i=1;i<=n;i++){
            if(a[i][1].idx!=flag)continue;
            if(num[a[i][2].idx]+1<=limit){
                if(reval<a[i][2].val){
                    reval=a[i][2].val;
                    reidx={i,2};
                }
            }else if(num[a[i][3].idx]+1<=limit){
                if(reval<a[i][3].val){
                    reval=a[i][3].val;
                    reidx={i,3};
                }
            }
        }
        sum-=a[reidx.first][1].val;
        sum+=a[reidx.first][reidx.second].val;
        num[a[reidx.first][reidx.second].idx]++;
        num[flag]--;
    }
    cout<<sum<<'\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
