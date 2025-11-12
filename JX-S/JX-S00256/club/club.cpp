#include<bits/stdc++.h>
using namespace std;
const int N=1E5+5;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,sum=0,d[N][N]={0},dbig[N][N]={0},s=-1,s2=0;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=3;k++){
                cin>>d[j][k];
                if(d[j][k]>s){
                    s=d[j][k];
                    s2=k;
                }
            }
            sum+=dbig[j][s2];
        }
        cout<<sum;
        sum=0;

    }
    return 0;
}
