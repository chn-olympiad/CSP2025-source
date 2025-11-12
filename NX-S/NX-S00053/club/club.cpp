#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long n,i,j,d,t,k,b,s;
    cin>>t;
    cin>>n;
    long long a[t][n][3];
    for(k=1;k<=t;k++){
        for(j=1;j<=n;j++){
            for(i=1;i<=3;i++){

                cin>>a[k][j][i];
            }
        }
    }
    long long avr=n/2,ans[t];
     for(k=1;k<=t;k++){
            j=3;
        for(i=1;i<=n;i++){
                ans[k]+=max(a[k][i][j],max(a[k][i][j-1],a[k][i][j-2]));

        }
    }
    for(k=1;k<=t;k++){
        cout<<ans[k]<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
