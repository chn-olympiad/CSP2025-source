#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r","stdin");
freopen("club.out","w",stdout);
int t,n,a1[999999],a2[999999],a3[999999];
int b1=0,b2=0,b3=0;
int c1[9],c2[9],c3[9];
cin>>t;
for(int j=1;j<=t;t++){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a1[i];
        cin>>a2[i];
        cin>>a3[i];
    }
    for(int i=1;i<=n;i++){
        int d=0,zhong=0;
        if(a1[i]>=a2[i] && a1[i]>=a3[i]){
            b1+=1;
            c1[d]=a1[i];
        }else if(a2[i]>=a1[i] && a2[i]>=a3[i]){
            b2+=1;
            c2[d]=a2[i];
        }else{
            b3+=1;
            c3[d]=a3[i];
        }
        if(b1%3==0){
            if(c1[1]<=c1[2] && c1[1]<=c1[3]){
                c1[1]=0;
            }else if(c1[2]<=c1[1] && c1[2]<=c1[3]){
                c1[2]=0;
            }else if(c1[3]<=c1[1] && c1[3]<=c1[2]){
                c1[3]=0;
            }
        }
        if(b2%3==0){
            if(c2[1]<=c2[2] && c2[1]<=c2[3]){
                c2[1]=0;
            }else if(c2[2]<=c2[1] && c2[2]<=c2[3]){
                c2[2]=0;
            }else if(c2[3]<=c2[1] && c2[3]<=c2[2]){
                c2[3]=0;
            }
        }
        if(b3%3==0){
            if(c3[1]<=c3[2] && c3[1]<=c3[3]){
                c3[1]=0;
            }else if(c3[2]<=c3[1] && c3[2]<=c3[3]){
                c3[2]=0;
            }else if(c3[3]<=c3[1] && c3[3]<=c3[2]){
                c3[3]=0;
            }
        }
        for(int j=1;j<=3;j++){
            zhong+=c1[i];
            zhong+=c2[i];
            zhong+=c3[i];
        }
        cout<<zhong<<endl;
    }
}
fclose(stdin);
fclose(stdout);
return 0;
}
