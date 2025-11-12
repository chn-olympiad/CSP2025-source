#include <bits/stdc++.h>
using namespace std;
int T,n,ans,a[100020][4],f[4],t,m=-1,mi=1;
int px(int a[100020][4],int y){
    int ma=-1;
    for(int i=1;i<=3;i++){
        if(a[y][i]>ma){
            ma=a[y][i];
            t=i;
        }
    }
    return ma;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >>T;
    while(T--){
        cin >>n;
        ans=0;memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin >>a[i][j];
                //f[i][j]=a[i][j];
            }
        }
       for(int i=1;i<=n;i++){
            m=-1;
            ans+=px(a,i);
            f[t]++;
            for(int k=1;k<=3;k++){
                if(f[k]>n/2){
                    ans-=px(a,i);
                    f[t]--;
                    for(int j=1;j<=3;j++){
                        if(i==t) continue;
                        if(a[i][j]>m){
                            m=a[i][j];
                            mi=j;
                        }
                    }
                    ans+=m;
                    f[mi]++;
                }
            }
       }
       cout <<ans<<endl;
    }
    return 0;
}//SMCSFWRZSBccf
