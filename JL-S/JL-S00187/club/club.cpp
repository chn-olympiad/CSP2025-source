#include<bits/stdc++.h>
using namespace std;
long long t,n;
struct people{
    long long a[3];
}p[10002];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    long long mx=-1;
    for(long long xx=0;xx<t;xx++){
        cin>>n;
        for(long long j=0;j<n;j++){
                cin>>p[j].a[0];
                cin>>p[j].a[1];
                cin>>p[j].a[2];
        }
        mx=-1;
        if(n==2){
            for(long long i=0;i<3;i++){
                for(long long j=0;j<3;j++){
                    if(i==j) continue;
                    if(p[0].a[i]+p[1].a[j]>mx){
                        mx=p[0].a[i]+p[1].a[j];
                    }
                }
            }
        }else if(n==4){
            for(long long i=0;i<3;i++){
                for(long long j=0;j<3;j++){
                    for(long long pp=0;pp<3;pp++){
                        for(long long qq=0;qq<3;qq++){
                            if((i==j&&i==pp&&i==qq)||(i==j&&i==pp)||(j==pp&&j==qq)||(i==pp&&i==qq)) continue;
                            if(p[0].a[i]+p[1].a[j]+p[2].a[pp]+p[3].a[qq]>mx){
                                mx=p[0].a[i]+p[1].a[j]+p[2].a[pp]+p[3].a[qq];
                            }
                        }
                    }
                }
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
