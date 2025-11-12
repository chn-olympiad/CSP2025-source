#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,ls=0,t,zb,l=0,h=0;
    cin>>a>>b;
    int num[a*b];
    for(int i=0;i<a*b;i++){
        cin>>num[i];
    }
    t=num[0];
    for(int i=0;i<a*b;i++){
        for(int j=0;j<a*b;j++){
            if(num[i]>num[j]){
                ls=num[i];
                num[i]=num[j];
                num[j]=ls;
            }
        }
    }
    for(int i=0;i<a*b;i++){
        if(num[i]==t){
            zb=i;
        }
    }
    zb+=1;
    if(zb%b==0){
        l=zb/a;
    }else{
        l=zb/a+1;
    }
    if(l%2==0){
        h=a-(zb%a)+1;
    }else{
        if(zb<=a){
            h=zb;
        }else{
            h=zb%a;
        }
    }
    cout<<l<<" "<<h;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

