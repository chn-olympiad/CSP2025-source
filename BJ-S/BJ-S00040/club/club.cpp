#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int k,a;
int t[100004][4];
int pd[100004];
int gn[4];
struct node{
    int n;
    int tp;
    int ps;
}h[300115];
bool cmp(node t1,node t2){
    return t1.n>t2.n;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>k;
    for(int i=0;i<k;i++){
       memset(t,0,sizeof(t));
        memset(pd,0,sizeof(pd));
        memset(gn,0,sizeof(gn));
        memset(h,0,sizeof(h));
        cin>>a;
        for(int i=0;i<a;i++){
            cin>>h[i*3].n;
            cin>>h[i*3+1].n;
            cin>>h[i*3+2].n;
            h[i*3].ps=i+1;
            h[i*3+1].ps=i+1;
            h[i*3+2].ps=i+1;
            h[i*3].tp=1;
            h[i*3+1].tp=2;
            h[i*3+2].tp=3;
        }
        int s=a*3;
        int cnt=0;
        long long ans=0;
        int done =0;
        sort(h,h+s+1,cmp);
        while(done<a && cnt<=s && h[cnt].n!=0){
            if(gn[h[cnt].tp]<(a/2) && !pd[h[cnt].ps]){
                gn[h[cnt].tp]++;
                ans+=h[cnt].n;
                pd[h[cnt].ps]++;
                done++;
            }
            cnt++;
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
//See you again
