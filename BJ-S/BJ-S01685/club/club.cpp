#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
struct node{
    //love, love val - second love val
    int l,lslv;
}a[N];
bool cmp(node x,node y){
    return x.lslv<y.lslv;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int l1=0,l2=0,l3=0,ans=0;
        for(int i=1;i<=n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            if(x>=y&&x>=z){
                l1++,ans+=x;
                a[i].l=1;
                a[i].lslv=x-max(y,z);
            }else if(y>=x&&y>=z){
                l2++,ans+=y;
                a[i].l=2;
                a[i].lslv=y-max(x,z);
            }else{
                l3++,ans+=z;
                a[i].l=3;
                a[i].lslv=z-max(x,y);
            }
            //cout<<a[i].l<<" "<<a[i].lv<<" "<<a[i].lslv<<"\n";
        }
        int up=max(l1,max(l2,l3));
        if(up>n/2){
            int whatup;
            if(up==l1)whatup=1;
            if(up==l2)whatup=2;
            if(up==l3)whatup=3;
            //cout<<up<<" "<<whatup;
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n;i++){
                if(up<=n/2){
                    cout<<ans;
                    break;
                }
                if(a[i].l==whatup){
                    up--;
                    ans-=a[i].lslv;
                }
            }
        }else cout<<ans;
        cout<<"\n";
    }
    return 0;
}
