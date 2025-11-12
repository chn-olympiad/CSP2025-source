#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,a[N],b[N],c[N],a2[N],b2[N],c2[N],maxx,cnt,ans,sum;
long long k;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j]>>b[j]>>c[j];
            if(a[j]==0){
                cnt++;
            }
            else if(b[j]==0){
                ans++;
            }
            else{
                sum++;
            }
        }
        if(ans==n&&sum==n&&cnt==n){
            cout<<0<<endl;
        }
        else if(cnt!=n&&ans==n&&sum==n){
            sort(a+1,a+n+1);
            for(int j=n;j>=n/2;j--){
                k+=a[j];
            }
            cout<<k<<endl;
            k=0;
        }
        else{
            for(int j=1;j<=n;j++){
                maxx=max(a[j],max(b[j],c[j]));
                if(maxx==a[j]){
                    if(cnt+1<=n/2){
                        a2[cnt]=a[j];
                        cnt++;
                        sort(a2,a2+cnt);
                    }
                    else{
                        if(a2[0]<a[j]){
                            a2[0]=a[j];
                            sort(a2,a2+cnt);
                        }
                    }
                }
                else if(maxx==b[j]){
                    if(ans+1<=n/2){
                        b2[ans]=b[j];
                        ans++;
                        sort(b2,b2+ans);
                    }
                    else{
                        if(b2[0]<b[j]){
                            b2[0]=b[j];
                            sort(b2,b2+ans);
                        }
                    }
                }
                else{
                    if(sum+1<=n/2){
                        c2[sum]=c[j];
                        sum++;
                        sort(c2,c2+sum);
                    }
                    else{
                        if(c2[0]<c[j]){
                            c2[0]=c[j];
                            sort(c2,c2+sum);
                        }
                    }
                }
            }
            for(int j=0;j<n;j++){
                k+=a2[j]+b2[j]+c2[j];
            }
            cout<<k<<endl;
            k=0;
        }
    }
    return 0;
}
