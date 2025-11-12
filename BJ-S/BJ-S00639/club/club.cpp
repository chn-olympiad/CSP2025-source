#include<bits/stdc++.h>
using namespace std;
long long n,a[100005][3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        long long sum1=1,sum2=1,sum3=1,p,q;
        for(int i=2;i<=n;i++){
            q=-1;
            for(int j=1;j<3;j++){
                q=max(q,a[i-1][j]);
            }
            a[i][0]+=q;
            if(sum1<n/2){
                p=a[i][0]+a[i-1][0];
                a[i][0]=max(a[i][0],a[i][0]+a[i-1][0]);
                if(a[i][0]==p) sum1++;
            }
            q=-1;
            for(int j=0;j<3;j++){
                if(j==1) continue;
                q=max(q,a[i-1][j]);
            }
            a[i][1]+=q;
            if(sum2<n/2){
                p=a[i][1]+a[i-1][1];
                a[i][1]=max(a[i][1],a[i][1]+a[i-1][1]);
                if(a[i][1]==p)  sum2++;
            }
            q=-1;
            for(int j=0;j<2;j++){
                q=max(q,a[i-1][j]);
            }
            a[i][2]=q;
            if(sum3<n/2){
                p=a[i][2]+a[i-1][2];
                a[i][2]=max(a[i][2],a[i][2]+a[i-1][2]);
                if(a[i][2]==p) sum3++;
            }
        }
        long long ma=-1;
        for(int j=0;j<3;j++){
            ma=max(a[n][j],ma);
        }
        cout<<ma<<endl;
    }
    return 0;
}
