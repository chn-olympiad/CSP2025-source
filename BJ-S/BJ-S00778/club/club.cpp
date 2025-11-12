#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,a[3],b[3],Maxa=0,numa=1,Maxb=0,numb=0,mida=0,midb=0;
    cin>>t;
    for(int j=1;j<=t;j++){
        cin>>n;
        for(int i=0;i<3;i++){
            cin>>a[i];
            if (Maxa < a[i]){
                Maxa = a[i];
                numa = i;
            }
            else{if(mida<a[i]){mida=a[i];}}
        }
        for(int i=0;i<3;i++){
            cin>>b[i];
            if (Maxb < b[i]){
                Maxb = b[i];
                numb = i;
            }
            else{if(midb<b[i]){midb=b[i];}}
        }
        if(numa!=numb){
            cout<<Maxa+Maxb;
        }
        else{
            if(Maxa+midb>=Maxb+mida){cout<<Maxa+midb;}
            else{cout<<Maxb+mida;}
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
