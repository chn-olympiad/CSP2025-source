#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    bool p=true;
    int a,b,azn=0,zx=1,j,l;
    cin>>a>>b;
    int c[a+1][b+1]={0};
    azn=a*b;
    int a12[azn+1]={0};
    int a_1[2]={0};
    for(int k=1;k<=azn;k++){
        cin>>a12[k];
        if(k==1){
            a_1[0]=a12[k];
        }
    }
    sort(a12+1,a12+azn+1);
    for(int i=1;i<=a;i++){
        j=b;
        while(j>0){
            if(p==true){
                    for(int k=1;k<=azn;k++){
                        l=a12[k];
                        c[j][i]=l;
                        cout<<c[j][i]<<endl;
                        if(c[j][i]==a_1[0]){
                            cout<<j<<" "<<i;
                            cout<<endl;
                            return 0;
                        }
                        if(k==azn){
                            p=false;
                        }
                    }
            }
            j--;
        }
    }
    return 0;
}
