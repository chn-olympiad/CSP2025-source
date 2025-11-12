#include<bits/stdc++.h>
using namespace std;
int n,s,b[100000][3]={-1,0,0},sum=0,x=0,z=0,b1=0,b2=0,b3=0,pan=0,c[3][4]={};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        int a[s][3]={};
        for(int j=0;j<s;j++){
            x=0,z=0,pan=0;
            for(int k=0;k<3;k++){
                cin>>a[j][k];
                if(a[j][k]>b[j][0]){
                    b[j][2]=b[j][1];
                    b[j][1]=b[j][0];
                    b[j][0]=a[j][k];
                    x++;
                }
                else if(a[j][k]<b[j][0]&&a[j][k]>b[j][1]){
                    b[j][2]=b[j][1];
                    b[j][1]=a[j][k];
                }
                else if(a[j][k]<b[j][0]&&a[j][k]<b[j][1]){
                    b[j][2]=a[j][k];
                    z++;
                }
                if(k==2&&x==2) pan++;
            }
            if(x==1) b1+=1;
            else if(x==3) b3+=1;
            else if(x==2&&z==1) b2+=1;
            else if(x==2&&pan==0) b2+=1;
            else if(x==2&&pan==1) b3+=1;
        }
        for(int i=0;i<s;i++){
            sum=sum+b[i][1];
        }
        cout<<sum;
        for(int j=0;j<s;j++){
            for(int k=0;k<3;k++){
                b[j][k]=-1;
            }
        }
        b1=0,b2=0,b3=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
