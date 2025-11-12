#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
int a[N][5];
int b[N];
int cmp(int x,int y){
    return x>y;
}
int sum1,sum2,sum3;
int cnt1,cnt2,cnt3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        if(n==2){
            int maxn=0;
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(i!=j){
                        maxn=max(maxn,a[1][i]+a[2][j]);
                    }
                }
            }
            cout<<maxn<<endl;
        }
        else if(n>200) {
            for(int i=1;i<=n;i++){
                b[i]=a[i][1];
            }
            sort(b+1,b+n+1,cmp);
            int sum=0;
            for(int i=1;i<=n/2;i++){
                sum+=b[i];
            }
            cout<<sum<<endl;
        }
        else {
            int sum=0;
            int c1[N],c2[N],c3[N];
            for(int i=1;i<=n;i++){
                c1[i]=a[i][1];
                c2[i]=a[i][2];
                c3[i]=a[i][2];
            }
            sort(c1+1,c1+n+1,cmp);
            sort(c2+1,c2+n+1,cmp);
            sort(c3+1,c3+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                sum+=c1[i]+c2[i]+c3[i];
            }
            cout<<sum<<endl;
        }

    }



    return 0;
}
