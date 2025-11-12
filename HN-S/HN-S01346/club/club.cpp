#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100010],b[100010],c[100010],s,d,ans,la,lb,lc;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        d=n;
        s=d/2;
        for(int j=1;j<=n;++j){
            cin>>a[j],b[j],c[j];
            if(a[j]>b[j]&&a[j]>c[j]){
                la++;
                ans+=a[j];
            }else if(b[j]>a[j]&&b[j]>c[j]){
                lb++;
                ans+=b[j];
            }else{
                lc++;
                ans+=c[j];
            }
            if(la>s){
                if(lb>s&&lc<s){
                    if(a[j]>b[j]){
                        ans-=b[j];
                    }else{
                        ans-=a[j];
                    }
                    ans+=c[j];
                }else if(lc>s&&lb<s){
                    if(a[j]>c[j]){
                        ans-=c[j];
                    }else{
                        ans-=a[j];
                    }
                    ans+=b[j];
                }else if(lb<s&&lc<s){
                    if(b[j]>c[j]){
                        ans+=b[j];
                    }else{
                        ans+=c[j];
                    }
                    ans-=a[j];
                }
            }else if(lb>s){
                if(la<s&&lc>s){
                    if(b[j]>c[j]){
                        ans-=c[j];
                    }else{
                        ans-=b[j];
                    }
                    ans+=a[j];
                }else if(la<s&&lc<s){
                    if(a[j]>c[j]){
                        ans+=a[j];
                    }else{
                        ans+=c[j];
                    }
                }
                ans-=b[j];
            }else if(lc>s&&la<s&&lb<s){
                if(a[j]>b[j]){
                    ans+=a[j];
                }else{
                    ans+=b[j];
                }
                ans-=c[j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
