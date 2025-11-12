#include<bits/stdc++.h>
#define long long
using namespace std;

signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int mm=n*m;
    int ts[mm+1];
    int h=0;
    for(int i=0;i<mm;i++){
        cin>>ts[i];
        if(i==0){
            h=ts[i];
        }
    }
    int zb=0;
    for(int i=1;i<mm;i++){
        for(int j=i;j>0;j--){
            if(ts[j]>ts[j-1]){
                zb=ts[j-1];
                ts[j-1]=ts[j];
                ts[j]=zb;
            }
        }
    }
    /*for(int i=0;i<mm;i++){
        cout<<ts[i]<<" ";
    }*/

    int room[n+1][m+1];
    int r=0;
    bool T=false;
    int ms=0,ns=0;
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                room[j][i]=ts[r];
                if(ts[r]==h){
                    ms=i;
                    ns=j;
                    cout<<ms<<" "<<ns;
                    T=true;
                    break;
                }
                r++;
            }
        }
        else{
            for(int j=n;j>0;j--){
                room[j][i]=ts[r];
                if(ts[r]==h){
                    ms=i;
                    ns=j;

                    cout<<ms<<" "<<ns;
                    T=true;
                    break;
                }
                r++;
            }
        }
        if(T){
            break;
        }
    }

    return 0;
}
