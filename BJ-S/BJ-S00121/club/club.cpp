#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
struct node{
    pair<int,int> a[4]={{0,0},{0,0},{0,0},{0,0}};
}e[N];
bool cmp1(pair<int,int> p1,pair<int,int> p2){
    return p1.first<p2.first;
}
bool cmp2(node n1,node n2){
    return n1.a[3].first-n1.a[2].first<n2.a[3].first-n2.a[2].first;
}
int cnt[4];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0;
        cnt[1]=cnt[2]=cnt[3]=0;
        for(int i=1;i<=n;i++){
            cin>>e[i].a[1].first>>e[i].a[2].first>>e[i].a[3].first;
            e[i].a[1].second=1,e[i].a[2].second=2,e[i].a[3].second=3;
            sort(e[i].a+1,e[i].a+3+1,cmp1);
            cnt[e[i].a[3].second]++;
            ans+=e[i].a[3].first;
        }
        sort(e+1,e+n+1,cmp2);
        for(int i=1;i<=n;i++){
            if(cnt[e[i].a[3].second]>n/2){
                ans-=e[i].a[3].first;
                ans+=e[i].a[2].first;
                cnt[e[i].a[3].second]--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
