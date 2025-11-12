#include<bits/stdc++.h>
using namespace std;
struct pp{
    int a1,a2,a3;
    int cha;
    int most;
};
bool cmp(pp a,pp b){
    return a.cha<b.cha;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int cl1=0,cl2=0,cl3=0;
        int n,ans=0,all=0;
        cin>>n;
        int maxx=n/2;
        struct pp a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            all+=max(max(a[i].a1,a[i].a3),a[i].a2);
            if(a[i].a1>a[i].a2&&a[i].a1>a[i].a3){a[i].most=1;cl1++;a[i].cha=a[i].a1-max(a[i].a2,a[i].a3);}
            else if(a[i].a2>a[i].a1&&a[i].a2>a[i].a3){a[i].most=2;cl2++;a[i].cha=a[i].a2-max(a[i].a1,a[i].a3);}
            else {a[i].most=3;cl3++;a[i].cha=a[i].a3-max(a[i].a2,a[i].a1);}

        }if(max(max(cl1,cl2),cl3)<=maxx){
            cout<<all<<'\n';
            continue;
        }else{
            int need=max(max(cl1,cl2),cl3)-maxx;
            int usi;
            if(cl1>cl2&&cl1>cl3)usi=1;
            else if(cl2>cl3&&cl2>cl1)usi=2;
            else usi=3;
            sort(a+1,a+n+1,cmp);
            for(int i=1;need;i++){
                if(a[i].most!=usi)continue;
                need--;
                all-=a[i].cha;
            }cout<<all<<'\n';
        }
    }
    return 0;
}
