#include<bits/stdc++.h>
using namespace std;
#define int long long
struct in{
    int c1,c2,c3;
    int ma;
    int mi;
    int mid;
};
bool cmp(in x,in y){
    return x.mid>y.mid;
}
int t,n;
in a[100050];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        int ma=n/2,mb=n/2,mc=n/2;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].c1>>a[i].c2>>a[i].c3;
            int tem[4];
            tem[1]=a[i].c1;
            tem[2]=a[i].c2;
            tem[3]=a[i].c3;
            sort(tem+1,tem+4);
            a[i].mid=tem[3]-tem[2];
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            int ans1=0,ans2=0,ans3=0;
            if(ma!=0){
                ans1=a[i].c1;
            }
            if(mb!=0){
                ans2=a[i].c2;
            }
            if(mc!=0){
                ans3=a[i].c3;
            }
            int cnt=ans;
            ans+=max(ans1,max(ans2,ans3));
            if(cnt+ans1==ans){
                ma--;
            }
            else if(cnt+ans2==ans){
                mb--;
            }
            else{
                mc--;
            }
        }
        cout<<ans<<'\n';
    }
}
