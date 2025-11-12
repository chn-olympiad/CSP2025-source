#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
struct node{
    int a1,a2,a3;
}a[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    //叫我打表王OvO
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
        }
        if(n==2){
            int sum[7];
            sum[0]=a[1].a1+a[2].a2;
            sum[1]=a[1].a1+a[2].a3;
            sum[2]=a[1].a2+a[2].a1;
            sum[3]=a[1].a2+a[2].a3;
            sum[4]=a[1].a3+a[2].a1;
            sum[5]=a[1].a3+a[2].a2;
            int maxn=0;
            for(int i=0;i<=5;i++){
                if(sum[i]>maxn){
                    maxn=sum[i];
                }
            }
            cout<<maxn<<endl;
        }
        if(n==4){
            int sum[55];
            sum[0]=a[1].a1+a[2].a1+a[3].a2+a[4].a2;
            sum[1]=a[1].a1+a[2].a1+a[3].a2+a[4].a3;
            sum[2]=a[1].a1+a[2].a1+a[3].a3+a[4].a2;
            sum[3]=a[1].a1+a[2].a1+a[3].a3+a[4].a3;
            sum[4]=a[1].a1+a[2].a2+a[3].a1+a[4].a2;
            sum[5]=a[1].a1+a[2].a2+a[3].a1+a[4].a3;
            sum[6]=a[1].a1+a[2].a2+a[3].a2+a[4].a1;
            sum[7]=a[1].a1+a[2].a2+a[3].a2+a[4].a3;
            sum[8]=a[1].a1+a[2].a2+a[3].a3+a[4].a1;
            sum[9]=a[1].a1+a[2].a2+a[3].a3+a[4].a2;
            sum[10]=a[1].a1+a[2].a2+a[3].a3+a[4].a3;
            sum[11]=a[1].a1+a[2].a3+a[3].a1+a[4].a2;
            sum[12]=a[1].a1+a[2].a3+a[3].a1+a[4].a3;
            sum[13]=a[1].a1+a[2].a3+a[3].a2+a[4].a1;
            sum[14]=a[1].a1+a[2].a3+a[3].a2+a[4].a2;
            sum[15]=a[1].a1+a[2].a3+a[3].a2+a[4].a3;
            sum[16]=a[1].a1+a[2].a3+a[3].a3+a[4].a1;
            sum[17]=a[1].a1+a[2].a3+a[3].a3+a[4].a2;
            sum[18]=a[1].a2+a[2].a1+a[3].a1+a[4].a2;
            sum[19]=a[1].a2+a[2].a1+a[3].a1+a[4].a3;
            sum[20]=a[1].a2+a[2].a1+a[3].a2+a[4].a1;
            sum[21]=a[1].a2+a[2].a1+a[3].a2+a[4].a3;
            sum[22]=a[1].a2+a[2].a1+a[3].a3+a[4].a1;
            sum[23]=a[1].a2+a[2].a1+a[3].a3+a[4].a2;
            sum[24]=a[1].a2+a[2].a1+a[3].a3+a[4].a3;
            sum[25]=a[1].a2+a[2].a2+a[3].a1+a[4].a1;
            sum[26]=a[1].a2+a[2].a2+a[3].a1+a[4].a3;
            sum[27]=a[1].a2+a[2].a2+a[3].a3+a[4].a1;
            sum[28]=a[1].a2+a[2].a2+a[3].a3+a[4].a3;
            sum[29]=a[1].a2+a[2].a3+a[3].a1+a[4].a1;
            sum[30]=a[1].a2+a[2].a3+a[3].a1+a[4].a2;
            sum[31]=a[1].a2+a[2].a3+a[3].a1+a[4].a3;
            sum[32]=a[1].a2+a[2].a3+a[3].a2+a[4].a1;
            sum[33]=a[1].a2+a[2].a3+a[3].a2+a[4].a3;
            sum[34]=a[1].a2+a[2].a3+a[3].a3+a[4].a1;
            sum[35]=a[1].a2+a[2].a3+a[3].a3+a[4].a2;
            sum[36]=a[1].a3+a[2].a1+a[3].a1+a[4].a2;
            sum[37]=a[1].a3+a[2].a1+a[3].a1+a[4].a3;
            sum[38]=a[1].a3+a[2].a1+a[3].a2+a[4].a1;
            sum[39]=a[1].a3+a[2].a1+a[3].a2+a[4].a2;
            sum[40]=a[1].a3+a[2].a1+a[3].a2+a[4].a3;
            sum[41]=a[1].a3+a[2].a1+a[3].a3+a[4].a1;
            sum[42]=a[1].a3+a[2].a1+a[3].a3+a[4].a2;
            sum[43]=a[1].a3+a[2].a2+a[3].a1+a[4].a1;
            sum[44]=a[1].a3+a[2].a2+a[3].a1+a[4].a2;
            sum[45]=a[1].a3+a[2].a2+a[3].a1+a[4].a3;
            sum[46]=a[1].a3+a[2].a2+a[3].a2+a[4].a1;
            sum[47]=a[1].a3+a[2].a2+a[3].a2+a[4].a3;
            sum[48]=a[1].a3+a[2].a2+a[3].a3+a[4].a1;
            sum[49]=a[1].a3+a[2].a2+a[3].a3+a[4].a2;
            sum[50]=a[1].a3+a[2].a3+a[3].a1+a[4].a1;
            sum[51]=a[1].a3+a[2].a3+a[3].a1+a[4].a2;
            sum[52]=a[1].a3+a[2].a3+a[3].a2+a[4].a1;
            sum[53]=a[1].a3+a[2].a3+a[3].a2+a[4].a2;
            int maxn=0;
            for(int i=0;i<=53;i++){
                if(sum[i]>maxn){
                    maxn=sum[i];
                }
            }
            cout<<maxn<<endl;
        }
    }
    return 0;
}
