#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
struct s{
    int bigest;
}myd[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        int a[100005],b[100005],c[100005];
        cin >> n;
        for(int f=0;f<n;f++){
            cin >> a[f] >> b[f] >> c[f];
            myd[f].bigest=max(max(a[f],b[f]),c[f]);
        }
        int ans=0;
        if(c[0]==0 && c[n-1]==0){
            if(b[0]==0 && b[n-1]==0){
                for(int j=0;j<n;j++){
                    a[j]=myd[j].bigest;
                }
                sort(a,a+n,cmp);
                for(int j=0;j<n/2;j++){
                    ans+=a[j];
                }
                cout << ans;
            }
            else{
                sort(a,a+n,cmp);
                sort(b,b+n,cmp);
                for(int j=0;j<n/2;j++){
                    if(b[j]>a[j]){
                        ans+=b[j];
                        a[j]=0;
                    }
                    else{
                        ans+=a[j];
                        b[j]=0;
                    }
                }
                cout << ans;
            }
        }
        //for(int j=0;j<n;j++){
        //    ans+=myd[j].bigest;
        //}
        //cout << ans;
    }
    return 0;
}
