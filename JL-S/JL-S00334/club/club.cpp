#include<bits/stdc++.h>
using namespace std;
int n[201],a[201],b[201],c[201],aj,bj,cj,cnt;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i];
        for(int j=1;j<=n[i];j++){
            cin>>a[i]>>b[i]>>c[i];
        }
        for(int j=1;j<=n[i];j++){
            sort(a+1,a+1+n[i]);
            sort(b+1,b+1+n[i]);
            sort(c+1,c+1+n[i]);
            for(int i=1;i<=3;i++){
                if(a[i]>b[i]&&a[i]>c[i]){
                   if(aj<n[i]/2){
                    aj++;
                    cnt+=aj;
                   }
                }
                if(b[i]>a[i]&&b[i]>c[i]){
                   if(bj<n[i]/2){
                    bj++;
                    cnt+=bj;
                   }
                }
                if(c[i]>b[i]&&c[i]>c[i]){
                   if(cj<n[i]/2){
                    cj++;
                    cnt+=cj;
                   }
                }
                else
                if(aj<n[i]/2){
                    aj++;
                    cnt+=aj;
                   }
                if(bj<n[i]/2){
                    bj++;
                    cnt+=bj;
                   }
                if(cj<n[i]/2){
                    cj++;
                    cnt+=cj;
                   }
            }
        }
        cout<<cnt;
    }
        return 0;
    }
