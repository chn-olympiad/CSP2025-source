#include<bits/stdc++.h>
using namespace std;
int n,m;
int a,b[1000],c,x=1,y=1,z;
bool d;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>b[i];
        if(i==0){
            a=b[i];
        }
    }
    for(int i=0;i<n*m-1;i++){
        for(int j=i+1;j<n*m;j++){
            if(b[i]<b[j]){
                c=b[i];
                b[i]=b[j];
                b[j]=c;
            }
        }
    }
    for(int i=0;i<n*m;i++){
        d=1;
        if(b[i]==a){
            break;
        }else{
            if((i+1)%n==0&&z==0){
                z=1;
                y++;
                d=0;
            }else{
                if((i+1)%n==0&&z==1){
                    z=0;
                    y++;
                    d=0;
                }
            }
        }
        if(z==0&&d){
            x++;
        }else{
            if(z==1&&d){
                x--;
            }
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
