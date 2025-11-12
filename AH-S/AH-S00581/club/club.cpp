#include<bits/stdc++.h>
using namespace std;
const int N=1e5+15;
int n,t,cnt[4];
struct node{
    int x,y,z,max1,mid,m1;
}s[N];
bool cmp(node a,node b){
    return (a.max1-a.mid)>(b.max1-b.mid);
}
bool cmp2(node a,node b){
    return abs(a.y-a.z)>abs(b.y-b.z);
}
bool cmp3(node a,node b){
    return abs(a.x-a.z)>abs(b.x-b.z);
}
bool cmp4(node a,node b){
    return abs(a.x-a.y)>abs(b.x-b.y);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();
    cin>>t;
    while(t--){
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        long long ans=0;
        for(int i=1;i<=n;i++){
            int x,y,z,max_,min_,m1;
            cin>>x>>y>>z;
            max_=max(x,max(y,z));
            if(max_==x)m1=1;
            else if(max_==y)m1=2;
            else m1=3;
            min_=min(x,min(y,z));
            s[i]={x,y,z,max_,x+y+z-max_-min_,m1};
        }
        sort(s+1,s+1+n,cmp);
        for(int i=1;i<=n;i++){
            if(cnt[s[i].m1]<n/2){
                ans+=s[i].max1;
                cnt[s[i].m1]++;
            }else{
                if(s[i].m1==1){
                    sort(s+i+1,s+n+1,cmp2);
                    for(int j=i;j<=n;j++)
                        ans+=max(s[j].y,s[j].z);
                }else if(s[i].m1==2){
                    sort(s+i+1,s+n+1,cmp3);
                    for(int j=i;j<=n;j++)
                        ans+=max(s[j].x,s[j].z);
                }else{
                    sort(s+i+1,s+n+1,cmp4);
                    for(int j=i;j<=n;j++)
                        ans+=max(s[j].x,s[j].y);
                }
                break;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
