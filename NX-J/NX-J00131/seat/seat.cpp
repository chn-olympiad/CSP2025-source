#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;
    int sum=m*n;
    int chen[105];
    cin>>chen[1];
    int se=chen[1];
    for(int i=2;i<=sum;i++){
        cin>>chen[i];
        while(chen[i]>=chen[i-1]){
            int temp=i;
        while(chen[temp]>=chen[temp-1]&&temp>1){
            swap(chen[temp],chen[temp-1]);
            temp--;

        }
    }
    }
    for(int i=1;i<=sum;i++){
        if(se==chen[i]){
            se=i;
            break;
        }
    }
    int p=1;
     for(int i=1;i<=n;i++){
        if(i%2==1){
        for(int j=1;j<=m;j++){
            if(se==p) {cout<<i<<" "<<j; break;}
           p++;
        }
        }
        else{
            for(int j=m;j>=1;j--){
            if(se==p) {cout<<i<<" "<<j; break;}
           p++;
        }
        }

     }
return 0;
}

