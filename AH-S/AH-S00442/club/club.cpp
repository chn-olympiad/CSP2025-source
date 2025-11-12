#include<bits/stdc++.h>
using namespace std;
int t,n,m1=0,m2=0,m3=0;
struct p{
    int a1,a2,a3;
}a[10005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
            int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
        }
        for(int i=1;i<=n;i++){
            if(max(a[i].a1,max(a[i].a2,a[i].a3))==a[i].a1){
                if(m1<n/2){
                    m1++;
                    ans+=a[i].a1;
                }
                else{
                    if(max(a[i].a2,a[i].a3)==a[i].a2){
                        if(m2<n/2){
                            m2++;
                            ans+=a[i].a2;
                        }
                        else{
                            m3++;
                            ans+=a[i].a3;
                        }
                    }
                    else{
                        if(m3<n/2){
                            m3++;
                            ans+=a[i].a3;
                        }
                        else{
                            m2++;
                            ans+=a[i].a2;
                        }
                    }
                }
            }
            else if(max(a[i].a1,max(a[i].a2,a[i].a3))==a[i].a2){
                if(m2<n/2){
                    m2++;
                    ans+=a[i].a2;
                }
                else{
                    if(max(a[i].a1,a[i].a3)==a[i].a1){
                        if(m1<n/2){
                            m1++;
                            ans+=a[i].a1;
                        }
                        else{
                            m3++;
                            ans+=a[i].a3;
                        }
                    }
                    else{
                        if(m3<n/2){
                            m3++;
                            ans+=a[i].a3;
                        }
                        else{
                            m1++;
                            ans+=a[i].a1;
                        }
                    }
                }
            }
            else{
                if(m3<n/2){
                    m3++;
                    ans+=a[i].a3;
                }
                else{
                    if(max(a[i].a2,a[i].a1)==a[i].a2){
                        if(m2<n/2){
                            m2++;
                            ans+=a[i].a2;
                        }
                        else{
                            m1++;
                            ans+=a[i].a1;
                        }
                    }
                    else{
                        if(m1<n/2){
                            m1++;
                            ans+=a[i].a1;
                        }
                        else{
                            m2++;
                            ans+=a[i].a2;
                        }
                    }
                }
            }
        }
    cout<<ans<<endl;
    }
    return 0;
}
