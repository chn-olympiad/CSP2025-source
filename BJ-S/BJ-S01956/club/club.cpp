#include<bits/stdc++.h>
using namespace std;
int n,s[100005][3],ka[100005],sati=0,a=0,b=0,c=0;
void fz(int k, int t){
    int lp=t-n/2;
    int ld=99999999,ldr,ldt;
    while(lp){
    for(int i=0; i<n; i++){
        if(ka[i]==k){
        if(s[i][k]-s[i][(k+1)%3]<ld){ld=s[i][k]-s[i][(k+1)%3];ldr=i;ldt=(k+1)%3;}
        if(s[i][k]-s[i][(k+2)%3]<ld){ld=s[i][k]-s[i][(k+2)%3];ldr=i;ldt=(k+2)%3;}
        }
    }
    ka[ldr]=ldt;
    sati-=ld;
    lp--;
    ld=99999999;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.ans","w",stdout);
    int A;
    cin>>A;
    for(int i=0; i<A; i++){

        cin>>n;
        for(int j=0; j<n; j++){
            cin>>s[j][0]>>s[j][1]>>s[j][2];
            if(s[j][0]>=s[j][1]&&s[j][0]>=s[j][2]){ka[j]=0;a++;}
            else if(s[j][1]>=s[j][0]&&s[j][1]>=s[j][2]){ka[j]=1;b++;}
            else if(s[j][2]>=s[j][1]&&s[j][2]>=s[j][0]){ka[j]=2;c++;}
            sati+=max(max(s[j][0],s[j][1]),s[j][2]);
        }

        if(a<=n/2&&b<=n/2&&c<=n/2){cout<<sati<<endl;}
        else{
        if(a>n/2){fz(0,a);}
            else if(b>n/2){fz(1,b);}
            else{fz(2,c);}

        cout<<sati<<endl;
        }
        a=b=c=sati=0;
    }


    return 0;
    fclose(stdin);
    fclose(stdout);
}
