#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,am,bm,cm;
struct matter{
    int a,b,c,mx,mn,ida,idb,idc;
    int d,e;
}k[N];
bool cmp(matter x,matter y){
    return x.mx>y.mx;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int m=n/2,sum=0;
        am=bm=cm=0;
        memset(k,0,sizeof(k));
        for(int i=1;i<=n;i++){
            cin>>k[i].a>>k[i].b>>k[i].c;
            k[i].mx=max({k[i].a,k[i].b,k[i].c});
            if(k[i].mx==k[i].a)k[i].ida=1;
            if(k[i].mx==k[i].b)k[i].idb=1;
            if(k[i].mx==k[i].c)k[i].idc=1;
        }
        sort(k+1,k+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(k[i].ida&&am<m){
                am++;
                sum+=k[i].mx;
            }
            else if(k[i].idb&&bm<m){
                bm++;
                sum+=k[i].mx;
            }
            else if(k[i].idc&&cm<m){
                cm++;
                sum+=k[i].mx;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
