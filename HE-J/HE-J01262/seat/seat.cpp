#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,zhong=0;
    cin>>n;
    cin>>m;
    int a=n*m+1;
    int seat[n*m];
    for(int i=1;i<=a;i++){
        cin>>c;
        seat[i]=c;
        }
    int b=seat[1];
    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            if(seat[j]<seat[j+1]){
                int zhong=0;
                zhong=seat[j];
                seat[j]=seat[j+1];
                seat[j+1]=zhong;
            }
        }
    }
    for(int i=1;i<=a;i++){
        if(seat[i]==b){
            if((i/m)==1){
                if((i/m+1)%2==0){
                        cout<<1<<" "<<i;
                }
            }
            if((i/m!=1)){
                if((i/m+1)%2==0){
                    cout<<i/m+1<<" "<<(m-i%m)+1;
                }
                if((i/m+1)%2!=0){
                    cout<<i/m+1<<" "<<i%m-1;
                }
            }
        }
    }
}





