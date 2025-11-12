#include<bits/stdc++.h>
using namespace std;
int f[500010],z[10010][25],kk[25],zui[25],fei=0,ddd=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a,b,c=0,d,e,te=0,jian=0;
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>f[i];
    }
    for(int i=1;i<=a;i++){
        if(f[i]>=2)jian=1;
    }
    if(b<=1&&jian==0){
        if(b==0){
            for(int i=1;i<=a;i++){
                if(f[i]==0){
                    c+=1;
                    te=0;
                }
                else if(f[i]==1){
                    te+=1;
                    if(te==2){
                        c+=1;
                        te=0;
                    }
                }
            }
            cout<<c;
            return 0;
        }
        else if(b==1){
            for(int i=1;i<=a;i++){
                if(f[i]==1){
                    c+=1;
                }
            }
            cout<<c;
        }
    }
    else if(a<=10000){
        for(int i=1;i<=a;i++){
            for(int j=1;j<=20;j++){
                z[i][j]=f[i]%2;
                f[i]=f[i]/2;
            }
        }
        for(int j=1;j<=20;j++){
                kk[j]=b%2;
                b=b/2;
            }
        for(int i=1;i<=a;i++){
                fei=0;
            for(int j=a;j>=ddd;j--){

                for(int k=1;k<=20;k++){
                    zui[k]+=z[j][k];
                }
                for(int j=20;j>=1;j--){
                    if(zui[j]%2!=kk[j])fei=1;
                }
                c=c+1-fei;
                if(fei==0)ddd=i;
                if(fei==0)break;
            }
            for(int j=25;j>=1;j--){
                zui[j]=0;
            }
        }
        cout<<c;
        return 0;
    }
    cout<<0;
    return 0;
}
