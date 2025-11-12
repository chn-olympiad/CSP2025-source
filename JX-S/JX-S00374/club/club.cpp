#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,w[N];
struct node{
    int r,t;
}x[N];
bool cmp(node a,node b){
    return a.t>b.t;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        cin>>n;
        ans=0;
        node a[5],s[5];
        for(int i=1;i<=4;i++)   s[i].t=0,s[i].r=i;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[1].t,&a[2].t,&a[3].t);
            a[1].r=1;a[2].r=2;a[3].r=3;
            sort(a+1,a+4,cmp);
            s[a[1].r].t++;
            w[i]=a[1].t;x[i].t=a[1].t-a[2].t;x[i].r=a[1].r;
        }
        sort(s+1,s+4,cmp);
        //cout<<s[1].r<<endl;
        for(int i=1;i<=n;i++){
            ans+=w[i];
        }
        if(s[1].t<=n/2){
            cout<<ans<<endl;
            continue;
        }
        int tot=s[1].t-n/2;//cout<<tot<<endl;
        sort(x+1,x+n+1,cmp);
        /*
        for(int i=n;i>=1;i--){
            cout<<x[i].t<<" "<<x[i].r<<endl;
        }*/
        for(int i=n;i>=1;i--){
            if(x[i].r==s[1].r){
                ans-=x[i].t;//cout<<x[i].r<<" "<<tot<<endl;
                tot--;
                if(tot==0){
                    break;
                }
            }
        }
        //cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}