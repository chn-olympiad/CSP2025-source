#include<bits/stdc++.h>
using namespace std;

int main (){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int c[10005]{};
    for(int i=0;i<=a*b-1;i++){
            cin>>c[i];
    }
    int ans=c[0];
    sort(c,c+(a*b),greater<int>());
    int aq[101][101];
    int sum=0;
    for(int i=0;i<=b-1;i++){
        if(i%2==0){
            for(int j=0;j<=a-1;j++){
                aq[j][i]=c[sum];
                sum++;
            }
        }
        else{
            for(int j=a-1;j>=0;j--){
                aq[j][i]=c[sum];
                sum++;
            }
        }
    }
    for(int i=0;i<=a-1;i++){
        for(int j=0;j<=b-1;j++){
           if(aq[i][j]==ans){
               cout<<j+1<<" "<<i+1;
               return 0;
           }
        }
        cout<<endl;
    }

    return 0;
}
