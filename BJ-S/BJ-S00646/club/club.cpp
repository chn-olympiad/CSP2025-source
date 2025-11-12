#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,MAXX1,MAXX2,MAXX3,manyidu,J1,J2,J3,cnt;
ll a1[100010],a2[100010],a3[100010],fav[100010],fav2[100010],fav3[100010];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a1[i]>>a2[i]>>a3[i];
        }
        for(int i=1;i<=n;i++){
            if(a1[i]>=a2[i]&&a1[i]>=a3[i]){
                fav[i]=a1[i];

            }
            if(a2[i]>=a1[i]&&a2[i]>=a3[i]){
                fav[i]=a2[i];

            }
            if(a3[i]>=a2[i]&&a3[i]>=a1[i]){
                fav[i]=a3[i];

            }
        }
        for(int i=1;i<=n;i++){
            cnt+=fav[i];
        }
        cout<<cnt;
    }
        /*for(int i=1;i<=3;i++){
            for(int j=1;j<=n/2;j++){
                if(a1[j]>MAXX1){
                    MAXX1=a1[j];
                    J1=j;
                }
                if(a2[j]>MAXX2){
                    MAXX2=a2[j];
                    J2=j;
                }
                if(a3[j]>MAXX3){
                    MAXX3=a3[j];
                    J3=j;
                }
            }
            cout<<MAXX1<<" "<<MAXX2<<" "<<MAXX3;
            manyidu+=MAXX1;
            manyidu+=MAXX2;
            manyidu+=MAXX3;
            a1[J1]=-10;
            a2[J2]=-10;
            a3[J3]=-10;
        }
        cout<<manyidu;
        manyidu=0;
        MAXX1=0;
        MAXX2=0;
        MAXX3=0;
    }*/
    return 0;
}
