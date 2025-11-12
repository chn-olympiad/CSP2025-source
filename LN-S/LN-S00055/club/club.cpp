#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct s{
    ll fir,sec,thr;
};
s a[100005];
ll b[100005];
ll c[100005][2];
struct s2{
    long long site,difference;
};
s2 d[100005];
int main()
{
    ios::sync_with_stdio();
    cin.tie(nullptr);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll t,n;
    ll a1,b1,c1;
    cin >> t;
    for (int i=1;i<=t;i++){
        cin >> n;
        ll ans=0;
        bool flag1=true,flag2=true;
        if (n==2){
            ll a2,b2,c2,max1=0,max2=0;
            cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
            max1=max(a1,b1);
            max1=max(max1,c1);
            max2=max(a2,b2);
            max2=max(max2,c2);
            if (max1==a1&&max2==b2||max1==a1&&max2==c2||max1==b1&&max2==a2||max1==b1&&max2==c2||max1==c1&&max2==a2||max1==c1&&max2==b2){
                ans=max1+max2;
            }
            else {
                ll min1,min2;
                if (max1==a1){
                    min1=a1-max(b1,c1);
                    min2=a2-max(b2,c2);
                }else if (max1==b1){
                    min1=b1-max(a1,c1);
                    min2=b2-max(a2,c2);
                }else {
                    min1=c1-max(a1,b1);
                    min2=c2-max(a2,b2);
                }
                if (min1<min2){
                    ans=max2;
                    if (b1>c1){
                        ans+=b1;
                    }
                    else {
                        ans+=c1;
                    }
                }
                else {
                    ans=max1;
                    if (b2>c2){
                        ans+=b2;
                    }
                    else {
                        ans+=c2;
                    }
                }
            }
        }
        else {
            for (int j=0;j<n;j++){
                cin >> a1 >> b1 >> c1;
                if (b1!=0){
                    flag1=false;
                }
                if (c1!=0){
                    flag2=false;
                }
                a[i].fir=a1,a[i].sec=b1,a[i].thr=c1;
            }
            if (flag1==true&&flag2==true){
                for (int i=0;i<n;i++){
                    b[i]=a[i].fir;
                }
                sort(b,b+n);
                for (int i=n-1;i>=n/2;i++){
                    ans+=b[i];
                }
            }
            else if (flag1==true){
                ll cnt1=0,cnt2=0;
                for (int i=0;i<n;i++){
                    c[i][0]=a[i].fir;
                    c[i][1]=a[i].thr;
                    d[i].difference=a[i].fir-a[i].thr;
                }
                for (int i=0;i<n;i++){
                    for (int j=i+1;j<n;j++){
                        if (d[i].difference<d[j].difference){
                            swap(d[i],d[j]);
                        }
                    }
                }
                for (int i=0;i<n;i++){
                    if (i<=n/2){
                        ans+=a[d[i].site].fir;
                    }
                    else {
                        ans+=a[d[i].site].thr;
                    }
                }
            }
            else if (flag2==true){
                ll cnt1=0,cnt2=0;
                for (int i=0;i<n;i++){
                    c[i][0]=a[i].fir;
                    c[i][1]=a[i].sec;
                    d[i].difference=a[i].fir-a[i].sec;
                }
                for (int i=0;i<n;i++){
                    for (int j=i+1;j<n;j++){
                        if (d[i].difference<d[j].difference){
                            swap(d[i],d[j]);
                        }
                    }
                }
                for (int i=0;i<n;i++){
                    if (i<=n-2){
                        ans+=a[d[i].site].fir;
                    }
                    else {
                        ans+=a[d[i].site].sec;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
