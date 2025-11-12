#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,cnt[4],ans;
struct Node{
    pair<int,int> a[4];
    int c;
}s[N];
bool USA(pair<int,int> x,pair<int,int> y){return x.first>y.first;}
bool CCCP(Node x,Node y){return ((x.c>y.c)||(x.c==y.c&&x.a[1].first>y.a[1].first));}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        cnt[1]=0; cnt[2]=0; cnt[3]=0; ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>s[i].a[j].first; s[i].a[j].second=j;
            }
        }
        for(int i=1;i<=n;i++)  {sort(s[i].a+1,s[i].a+1+3,USA); s[i].c=s[i].a[1].first-s[i].a[2].first;}
        sort(s+1,s+1+n,CCCP);
        for(int i=1;i<=n;i++){
            if(cnt[s[i].a[1].second]>=n/2) ans+=s[i].a[2].first;
            else {cnt[s[i].a[1].second]++;ans+=s[i].a[1].first;}
        }
        cout<<ans<<"\n";
    }
    return 0;
}
