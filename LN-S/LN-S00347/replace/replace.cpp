#include<bits/stdc++.h>
using namespace std;
int t,n,ans,lst,lst2;
stack<int>c[5];
struct b{
    int l[50],m,m2;
}a[100005];
bool cmp(b x,b y){
return max({x.l[0],x.l[1],x.l[2]})>max({y.l[0],y.l[1],y.l[2]});}
// |       | |       | |       |                            |       |
// |       | |       | |       |                            |       |
// |       | |       | |       |                            |       |
// |       | |       | |       |                            |       |
// |       | |       | |       |                            |       |
// |       | |       | |       |                            |       |
// |       | |       | |       |                            |       |
// |       | |       | |       |                            |       |
// |       | |       | |       |                            |       |
// |       | |       | |       |                            |       |
// |       | |       | |       |                            |       |
// |       | |       | |       |                            |       |
// |       | |       | |       |                            |       |
// |       | |       | |       |                            |       |
// |       | |       | +———————+                            |       |
// |       | +———————+                                      |       |
// +———————+                                                |    +  |
//                                                        + |       |+
//                                                          |  +    |
//                                                       +  |   _  +|  +
//——————————————————————————————————————————————————————————|  |_|  |—————
//                                                           +        +
//                                                       +         +
//                                                              +
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>t;
    while(t--){ans=0;
    while(!c[1].empty())c[1].pop();
    while(!c[2].empty())c[2].pop();
    while(!c[3].empty())c[3].pop();
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].l[0]>>a[i].l[1]>>a[i].l[2];
            if(a[i].l[0]>a[i].l[1])a[i].m=1;else a[i].m=2;
            if(a[i].l[a[i].m]<a[i].l[2])a[i].m=3;
            if(a[i].l[0]<a[i].l[1])a[i].m2=1;else a[i].m2=2;
            if(a[i].l[a[i].m2]>a[i].l[2])a[i].m2=3;}
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++){
            c[a[i].m].push(i);
            if(c[a[i].m].size()<n/2){
                if(c[a[i].m].empty())
                ans+=a[i].l[a[i].m];
                else
                if(a[c[lst].top()].l[3-a[c[lst].top()].m-a[c[lst].top()].m2]+a[i].l[a[i].m]>a[c[lst].top()].l[lst]){
                    c[a[i].m].pop();
                    c[lst].pop();
                    c[lst].push(i);
                    c[3-a[lst2].m-a[lst2].m2].push(lst2);
                    ans+=a[c[lst].top()].l[3-a[c[lst].top()].m-a[c[lst].top()].m2]+a[i].l[a[i].m];
            }
            }
            else{
                if(a[c[lst].top()].l[3-a[c[lst].top()].m-a[c[lst].top()].m2]+a[i].l[a[i].m]>a[c[lst].top()].l[lst]){
                    c[a[i].m].pop();
                    c[lst].pop();
                    c[lst].push(i);
                    c[3-a[lst2].m-a[lst2].m2].push(lst2);
                    ans+=a[c[lst].top()].l[3-a[c[lst].top()].m-a[c[lst].top()].m2]+a[i].l[a[i].m];
            }else ans+=a[i].l[3-a[i].m-a[i].m2];
            }
            lst=a[i].m;lst2=i;
        }cout<<ans<<endl;
    }cout<<ans;
    return 0;
}
