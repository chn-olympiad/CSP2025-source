#include<bits/stdc++.h>
using namespace std;
int n,t,a[100100],b[100100],c[100100],c1,c2,c3,myd1,myd2;

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        myd1=0;
        myd2=0;
        c1=0;
        c2=0;
        c3=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }

        for(int i=1;i<=n;i++){
            if(a[i]>=b[i]&&a[i]>=c[i]&&c1<n/2){
                c1++;
                myd1+=a[i];
            }
            if(b[i]>=a[i]&&b[i]>=c[i]&&c2<n/2){
                c2++;
                myd1+=b[i];
            }
            if(c[i]>=a[i]&&c[i]>=b[i]&&c3<n/2){
                c3++;
                myd1+=c[i];
            }
        }

        c1=0;
        c2=0;
        c3=0;
        for(int i=1;i<=n;i++){
            if(a[i]>=b[i]&&a[i]>=c[i]&&c1<n/2){
                if(a[i]-a[i+1]<=b[i]-b[i+1]&&b[i]-b[i+1]>=c[i]-c[i+1]){
                    c2++;
                    myd2+=b[i];
                }else if(a[i]-a[i+1]>=b[i]-b[i+1]&&a[i]-a[i+1]>=c[i]-c[i+1]){
                    c1++;
                    myd2+=a[i];
                }else{
                    c3++;
                    myd2+=c[i];
                }
            }else if(b[i]>=a[i]&&b[i]>=c[i]&&c2<n/2){
                if(a[i]-a[i+1]<=b[i]-b[i+1]&&b[i]-b[i+1]>=c[i]-c[i+1]){
                    c2++;
                    myd2+=b[i];
                }else if(a[i]-a[i+1]>=b[i]-b[i+1]&&a[i]-a[i+1]>=c[i]-c[i+1]){
                    c1++;
                    myd2+=a[i];
                }else{
                    c3++;
                    myd2+=c[i];
                }
            }else if(c[i]>=a[i]&&c[i]>=b[i]&&c3<n/2){
                if(a[i]-a[i+1]<=b[i]-b[i+1]&&b[i]-b[i+1]>=c[i]-c[i+1]){
                    c2++;
                    myd2+=b[i];
                }else if(a[i]-a[i+1]>=b[i]-b[i+1]&&a[i]-a[i+1]>=c[i]-c[i+1]){
                    c1++;
                    myd2+=a[i];
                }else{
                    c3++;
                    myd2+=c[i];
                }
            }
        }
        cout<<max(myd1,myd2)<<endl;
    }
    return 0;
}
