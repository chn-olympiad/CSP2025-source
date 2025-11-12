#include<bits/stdc++.h>
using namespace std;
int b[10000]={0};
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,c=0;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>b[i];
    }
    int d;
    for(int i=0;i<a-2;i++){
            for(int j=i+1;j<a-1;j++){
                for(int k=j+1;k<a;k++){
                    if(b[i]>b[j]){
                        if(b[i]>b[k]){
                            d=b[i];
                        }
                        else{
                            d=b[k];
                        }
                    }
                    else{
                        if(b[j]>b[k]){
                            d=b[j];
                        }
                        else{
                            d=b[k];
                        }
                    }
                    if(b[i]+b[j]+b[k]>d*2){
                        c++;
                    }
                }
            }
        }
    if(a>=4){
        for(int i=0;i<a-3;i++){
            for(int j=i+1;j<a-2;j++){
                for(int k=j+1;k<a-1;k++){
                    for(int l=k+1;l<a;l++){
                        d=-1;
                        if(b[i]>d){
                            d=b[i];
                        }
                        if(b[j]>d){
                            d=b[j];
                        }
                        if(b[k]>d){
                            d=b[k];
                        }
                        if(b[l]>d){
                            d=b[l];
                        }
                        if(b[i]+b[j]+b[k]+b[l]>d*2){
                            c++;
                        }
                    }
                }
            }
        }
    }
    if(a>=5){
        d=-1;
        for(int i=0;i<5;i++){
            if(b[i]>d){
                d=b[i];
            }
        }
        if(b[0]+b[1]+b[2]+b[3]+b[4]>d*2){
            c++;
        }
    }
    cout<<c;
}
