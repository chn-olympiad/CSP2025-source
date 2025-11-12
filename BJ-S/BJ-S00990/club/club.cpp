#include<bits/stdc++.h>
using namespace std;
int n,t,ans,ans2;
struct uct {
    int t[4];
}a[100005];
bool cmp1 (uct x,uct y){
    if(max(max(x.t[1],x.t[2]),x.t[3]) > max(max(y.t[1],y.t[2]),y.t[3]))
        return 1;
    if(max(max(x.t[1],x.t[2]),x.t[3]) == max(max(y.t[1],y.t[2]),y.t[3]))
        return min(min(x.t[1],x.t[2]),x.t[3]) < min(min(y.t[1],y.t[2]),y.t[3]);
    return 0;
}
bool cmp2 (uct x,uct y){
    if(min(min(x.t[1],x.t[2]),x.t[3]) < min(min(y.t[1],y.t[2]),y.t[3]))
        return 1;
    return 0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int ti = 0;ti<t;ti++){
        cin>>n;
        int p[4] = {0,0,0,0};
        for(int i=1;i<=n;i++){
            cin>>a[i].t[1]>>a[i].t[2]>>a[i].t[3];
        }
        sort(a+1,a+n+1,cmp1);
        for(int i=1;i<=n;i++){
            int maxn = 0,id =0,sc =0,maxsc = 0;
            for(int j=1;j<=3;j++){
                if(a[i].t[j] > maxn){
                    maxsc = maxn;
                    maxn = a[i].t[j];
                    sc = id;
                    id = j;
                    //cout<<"j:"<<j<<endl;
                }
                else if(a[i].t[j] > maxsc){
                    maxsc = a[i].t[j];
                    sc = j;
                    //cout<<"j:"<<j<<endl;
                }
            }
            if(p[id] + 1 <= n/2){
                p[id] += 1;
                ans += maxn;
                //cout<<i<<maxn<<" "<<maxsc<<" "<<id<<" "<<sc<<endl;
            }
            else {
                p[sc] += 1;
                ans += maxsc;
                //cout<<id<<" "<<n/2<<" ";
                //cout<<i<<" "<<maxn<<" "<<maxsc<<" "<<sc<<endl;
            }
        }
        p[1] = 0,p[2] = 0,p[3] = 0;
        sort(a+1,a+n+1,cmp2);
        for(int i=1;i<=n;i++){
            int maxn = 0,id =0,sc =0,maxsc = 0;
            for(int j=1;j<=3;j++){
                if(a[i].t[j] > maxn){
                    maxsc = maxn;
                    maxn = a[i].t[j];
                    sc = id;
                    id = j;
                    //cout<<"j:"<<j<<endl;
                }
                else if(a[i].t[j] > maxsc){
                    maxsc = a[i].t[j];
                    sc = j;
                    //cout<<"j:"<<j<<endl;
                }
            }
            if(p[id] + 1 <= n/2){
                p[id] += 1;
                ans2 += maxn;
                //cout<<maxn<<endl;
                //cout<<i<<maxn<<" "<<maxsc<<" "<<id<<" "<<sc<<endl;
            }
            else {
                p[sc] += 1;
                ans2 += maxsc;
                //cout<<maxsc<<endl;
                //cout<<id<<" "<<n/2<<" ";
                //cout<<i<<" "<<maxn<<" "<<maxsc<<" "<<sc<<endl;
            }
        }
        cout<<max(ans2,ans)<<endl;
        ans = 0;
        ans2= 0;
    }
    return 0;
}
