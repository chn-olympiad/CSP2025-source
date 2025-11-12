#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
long long a[100005];
long long b[100005];
long long c[100005];
long long ma[1000005];
long long mb[1000005];
long long mc[1000005];
long long s;
        int la,lb,lc;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
for(int lll=1;lll<=t;lll++){
    cin>>n;
        s=0;
        la=0,lb=0,lc=0;
        fill(a+1,a+5+n,0);
        fill(b+1,b+5+n,0);
        fill(c+1,c+5+n,0);
        fill(ma+1,ma+5+n,0);
        fill(mb+1,mb+5+n,0);
        fill(mc+1,mc+5+n,0);
    int k=n/2;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        int j=0;
              if(a[i]>=b[i]&&a[i]>=c[i]){
            la++;
            j++;
                ma[la]=a[i]-max(b[i],c[i]);
            if(la<=k){s+=a[i];
        }
        else {
            sort(ma+1,ma+1+la);
            s+=a[i];
            s-=ma[1];
            ma[1]=1e9+5;
                 }
}

        if(j==0) if(b[i]>=a[i]&&b[i]>=c[i]){
            lb++;
            j++;
                mb[lb]=b[i]-max(a[i],c[i]);
            if(lb<=k){s+=b[i];
        }
        else {
            sort(mb+1,mb+1+lb);
            s+=b[i];
            s-=mb[1];
            mb[1]=1e9+5;
        }}

         if(j==0) if(c[i]>=b[i]&&c[i]>=a[i]){
            lc++;
                mc[lc]=c[i]-max(b[i],a[i]);
            if(lc<=k){s+=c[i];
        }
        else {
            sort(mc+1,mc+1+lc);
            s+=c[i];
            s-=mc[1];
            mc[1]=1e9+5;
        }
    }
}
cout<<s<<endl;
}
return 0;
}

