#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    int t;
    cin>>t;
    for(int bx_99=1;bx_99<=t;bx_99++){
        cin>>n;
        int myd=0;
        int a[n][3];
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }

        int b1[10010],b2[10010],b0[10010];
        memset(b0,0,sizeof(b0));
        memset(b1,0,sizeof(b1));
        memset(b2,0,sizeof(b2));
        int bj1=0,bj2=0,bj0=0;
    int sb0=0,sb1=0,sb2=0;
        for(int i=0;i<n;i++){
        if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){b0[bj0]=i;bj0++;myd+=a[i][0];sb0++;}
        if(a[i][1]>a[i][0]&&a[i][1]>a[i][2]){b1[bj1]=i;bj1++;myd+=a[i][1];sb1++;}
        if(a[i][2]>a[i][1]&&a[i][2]>a[i][0]){b2[bj2]=i;bj2++;myd+=a[i][2];sb2++;}
        if(a[i][0]==a[i][1]&&a[i][0]>a[i][2]){b0[bj0]=i;bj0++;myd+=a[i][0];sb0++;}
        if(a[i][0]==a[i][2]&&a[i][2]>a[i][1]){b0[bj0]=i;bj2++;myd+=a[i][2];sb2++;}
        if(a[i][1]==a[i][2]&&a[i][1]>a[i][0]){b0[bj0]=i;bj1++;myd+=a[i][1];sb1++;}
        if(a[i][1]==a[i][2]&&a[i][2]==a[i][0]){b0[bj0]=i;bj0++;myd+=a[i][0];sb0++;}
    }
    int jian=0;
    int c[100];
    int j114=0;
    memset(c,99,sizeof(c));
    jian=0;



    if(sb2>n/2){
        for(int i=0;i<n;i++){
            if(a[i][2]==a[i][1]||a[i][0]==a[i][2]){
                sb2--;
                if(sb2<=n/2){break;}
            }
            if(a[i][2]>a[i][0]&&a[i][2]>a[i][1]){
                c[j114]=min(a[i][2]-a[i][0],a[i][2]-a[i][1]);
            }
        }
        for(int i=0;i<sb2-n/2;i++){
            if(c[i]>=20000){
                c[i]=1;
            }
            jian+=c[i];
        }
    myd-=jian;
    }




    if(sb1>n/2){
        for(int i=0;i<n;i++){
            if(a[i][0]==a[i][1]||a[i][1]==a[i][2]){
                sb1--;
                if(sb1<=n/2){break;}
            }
            if(a[i][1]>a[i][0]&&a[i][1]>a[i][2]){
                c[j114]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
            }
        }
        for(int i=0;i<sb1-n/2;i++){
            if(c[i]>=20000){
                c[i]=1;
            }
            jian+=c[i];
        }
    myd-=jian;
    }


    if(sb0>n/2){
        for(int i=0;i<n;i++){
            if(a[i][0]==a[i][1]||a[i][0]==a[i][2]){
                sb0--;
                if(sb0<=n/2){break;}
            }
            if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
                c[j114]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
            }
        }
       if(sb0>n/2){
    sort(c,c+j114);
        for(int i=0;i<j114;i++){
            for(int j=1;j<j114;j++){
                if(c[j]<c[j-1]){
                    int t=c[i];
                    c[i]=c[i-1];
                    c[i-1]=t;
                }
            }
        }
        for(int i=0;i<sb0-n/2;i++){
            if(c[i]>=20000){
                c[i]=1;
            }
            jian+=c[i];
        }
       }
        myd-=jian;
    jian=0;
    }




    cout<<myd<<endl;
    }



    return 0;
}
