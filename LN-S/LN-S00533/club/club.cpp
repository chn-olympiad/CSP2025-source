#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll fir,sec,thi;
    ll w;
}a[1000005];
bool cmp1(node x,node y){
    return x.fir>y.fir;
}
int f[100006],s[100005],t[100006];
int choice1[1000005],choice2[1000005],choice3[1000005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;
    while(T--){
        ll n;
        cin>>n;
        ll m = n/2,f1 = 0,f2 = 0;
        for(ll i = 1;i<=n;i++){
            cin>>a[i].fir>>a[i].sec>>a[i].thi;
            f[i] = a[i].fir;s[i] = a[i].sec;t[i] = a[i].thi;
            a[i].w = i;
            if(a[i].sec!=0) f1 = 1;
            if(a[i].thi!=0) f2 = 1;
        }
        if(!f1 && !f2){
            sort(a+1,a+1+n,cmp1);
            ll sum = 0;
            for(ll i = 1;i<=m;i++) sum+=a[i].fir;
            cout<<sum<<endl;
        }
        else{
            ll l1 = 0,l2 = 0,l3 = 0;
            for(int i = 1;i<=n;i++){
                if(f[i]>=s[i] && f[i]>=t[i]){
                    choice1[++l1] = f[i];
                }else if(s[i]>=f[i] && s[i]>=t[i]){
                    choice2[++l2] = s[i];
                }else if(t[i]>=f[i] && t[i]>=s[i]){
                    choice3[++l3] = t[i];
                }
            }
            sort(choice1+1,choice1+1+l1,cmp);
            ll ans = 0;
            for(int i = 1;i<=min(m,l1);i++){
                ans+=choice1[i];
            }
            if(m<l1){
                for(int i = m+1;i<=l1;i++){
                    for(int j = 1;j<=n;j++){
                        if(f[j]==choice1[i]){
                            choice2[++l2] = s[j];
                            break;
                        }
                    }
                }
            }
            sort(choice2+1,choice2+1+l2,cmp);
            for(int i = 1;i<=min(m,l2);i++){
                ans+=choice2[i];
            }
            if(m<l2){
                for(int i = m+1;i<=l2;i++){
                    for(int j = 1;j<=n;j++){
                        if(f[j]==choice2[i]){
                            choice3[++l3] = t[j];
                            break;
                        }
                    }
                }
            }
            sort(choice3+1,choice3+1+l3,cmp);
            for(int i = 1;i<=m;i++) ans+=choice3[i];
            cout<<ans<<endl;
        }
    }
    return 0;
}
