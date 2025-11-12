#include<bits/stdc++.h>
using namespace std;
int a[100005][4],n,T;
int c[4][100001],d[4];
long long sum;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        sum=0;
        d[1]=d[2]=d[3]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int ma=max(a[i][1],max(a[i][2],a[i][3])),mx;
            int mi=min(a[i][1],min(a[i][2],a[i][3]));
            for(int j=1;j<=3;j++){
                if(ma==a[i][j]) mx=j;
            }
            c[mx][++d[mx]]=2*ma+mi-a[i][1]-a[i][2]-a[i][3];
            sum+=ma;
        }
        for(int i=1;i<=3;i++){
            if(d[i]>n/2){
                sort(c[i]+1,c[i]+d[i]+1);
                for(int j=1;j<=d[i]-(n/2);j++){
                    sum-=c[i][j];
                }
            }
        }
        cout<<sum<<endl;
    }
}
