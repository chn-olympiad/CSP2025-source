#include<bits/stdc++.h>
using namespace std;
bool dl[1000][1000];
int price[1000][1000];
int csh[1000];
int csdl[1000][1000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int a,b,c,ans=0;
    cin>>a>>b>>c;
    for(int i=0;i<b;i++){
        int d,e,f;
        cin>>d>>e>>f;
        price[d][e]=f;
    }
    for(int j=0;j<c;j++){

        int d;
        cin>>d;
        int cshprice=d;
        csh[j]=d;
        int jsjg=0;

        for(int k=1;k<n;k++){
            int e;
            cin>>e;
            csdl[j][k]=e
            jsjg+=price[j][k]-e;

        }
        if(jsjd>chsprice){
            ans+=chsprice;
            for(int k=0;k<n;k++){
                ans+=csdl[j][k];
                dl[j][k]=true;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!dl[i][j]){
                ans+=price[i][j];
                dl[i][j]=true;
            }
        }
    }
    cout<<ans;
    return 0;
}