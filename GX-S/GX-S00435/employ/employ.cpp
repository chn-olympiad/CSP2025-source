#include<bits/stdc++.h>
using namespace std;
int a,b,c,d[5001][2],f=1;

int main(){
                    freopen("employ.in","r",stdin);
                    freopen("employ.out","w",stdout);
    cin>>a>>b;
    cin>>c;
    int e=a;
    while(e!=0){
        d[e][1]=c%10;
        e--;
    }
    for(int i=1;i<=a;i++){
        cin>>d[i][2];
    }
    int e=1;
    for(int i=1;i<=a;i++){
        for(int j=i;j<=a;j++){
            if(d[j][2]>d[j+1][2]){
                int z=0;
                z=d[j][2];
                d[j][2]=d[j+1][2];
                d[j+1][2]=z;
            }

        }
    }
    for(int i=1;i<=a;i++){
        if(d[i][2]==d[i+1][2]){
            e++;
        }else{
            f*=e;
            e=1;
        }

    }

    cout<<f;
}
