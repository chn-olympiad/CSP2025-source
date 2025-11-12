#include <bits/stdc++.h>
using namespace std;
int a[100050];
int b[100050];
int c[100050];
int loss1[100050];
int loss2[100050];
int loss3[100050];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int j=1;j<=t;++j){
        int n,ans=0;
        int s1=0,s2=0,s3=0;
        cin>>n;
        int mid=(n/2);
        for(int i=1;i<=n;++i){
            cin>>a[i]>>b[i]>>c[i];
            int d=max(a[i],b[i]);
            int e=max(d,c[i]);
            if(e==d){
                if(d==a[i]){
                    int sec=max(b[i],c[i]);
                    if(a[i]==b[i]){
                        if(s1<=s2){
                            loss1[i]=e-sec;
                            ans+=e;
                            s1++;
                        }
                        else{
                            loss2[i]=e-sec;
                            ans+=e;
                            s2++;
                        }
                    }
                    else{
                        loss1[i]=e-sec;
                        s1++;
                        ans+=e;
                    }
                }
                else{
                    int sec=max(a[i],c[i]);
                    loss2[i]=e-sec;
                    ans+=e;
                    s2++;
                }
            }
            else{
                int sec=d;
                s3++;
                ans+=e;
                loss3[i]=e-sec;
            }
        }
         if(s1>mid){
                int k=s1-mid;
                sort(loss1+1,loss1+s1+1);
                for(int i=1;i<=k;++i){
                    ans-=loss1[i];
                }
                cout<<ans<<endl;
                continue;
            }
            if(s2>mid){
                int k=s2-mid;
                sort(loss2+1,loss2+s2+1);
                for(int i=1;i<=k;++i){
                    ans-=loss2[i];
                }
                cout<<ans<<endl;
                continue;
            }
            if(s3>mid){
                int k=s3-mid;
                sort(loss3+1,loss3+s3+1);
                for(int i=1;i<=k;++i){
                    ans-=loss3[i];
                }
                cout<<ans<<endl;
                continue;
            }
            cout<<ans<<endl;
    }
    return 0;
}

