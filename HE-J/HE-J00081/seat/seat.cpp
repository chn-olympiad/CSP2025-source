#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,temp=0,xms;
    cin>>n>>m;
    int se[n*m+1];
    cin>>xms;
    for(int i=1;i<=n*m-1;i++){
        cin>>se[i];
    }
    se[0]=xms;
    for(int j=1;j<=n*m;j++){
        for(int i=1;i<=n*m;i++){
             if(se[i]>se[i-1]){
                temp=se[i-1];
                se[i-1]=se[i];
                se[i]=se[i-1];
                j--;
                i--;
            }
        }
    }
    int a=0,b=0;
    for(int j=0;j<=n*m;j++){
        for(int i=0;i<=n*m;i++){
            if(se[j*i+1]==xms){
                b=i/n+1;
                a=i%m;
            }
        }
    }
    cout<<a<<" "<<b;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
