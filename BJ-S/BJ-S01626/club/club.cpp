#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int T,n,cnt[4],ans,id,d;
struct Node{pair<int,int> a[4];}a[N];
bool cmp(Node a,Node b){return a.a[0].first-a.a[1].first<b.a[0].first-b.a[1].first;}
void swp(pair<int,int> &l,pair<int,int> &r){if(l<r) swap(l,r);}
void f(Node &nd){
    swp(nd.a[0],nd.a[1]);
    swp(nd.a[1],nd.a[2]);
    swp(nd.a[0],nd.a[1]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cnt[0]=cnt[1]=cnt[2]=0,ans=0,id=-1,d=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i].a[j].first;
                a[i].a[j].second=j;
            }
            f(a[i]);
            cnt[a[i].a[0].second]++;
            ans+=a[i].a[0].first;
        }
        for(int i=0;i<3;i++) if(cnt[i]>(n>>1)) id=i,d=cnt[i]-(n>>1);
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n&&d;i++)
            if(a[i].a[0].second==id){
                ans-=a[i].a[0].first-a[i].a[1].first;
                d--;
            }
        cout<<ans<<endl;
    }
    return 0;
}