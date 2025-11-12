#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r","stdin");
    freopen("polygon.out","w","stdout");
    int a,b[5005],cnt=0;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b[i];
    }for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            for(int k=1;k<=a;k++){
                if(b[i]+b[j]+b[k]>2*b[i]&&b[i]+b[j]+b[k]>2*b[j]&&b[i]+b[j]+b[k]>2*b[k]){
                    cnt++;
                }
            }
        }
    }for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            for(int k=1;k<=a;k++){
                for(int l=1;l<=a;l++){
                    if(b[i]+b[j]+b[k]+b[l]>2*b[i]&&b[i]+b[j]+b[k]+b[l]>2*b[j]&&b[i]+b[j]+b[k]+b[l]>2*b[k]&&b[i]+b[j]+b[k]+b[l]>2*b[l]){
                        cnt++;
                    }
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
