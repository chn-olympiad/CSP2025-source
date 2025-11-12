#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,m=0,a[100001][4],x[4]={0,0,0,0},s[100001],c[100001],l=-1,og[3],mn,qw[3],vv,se;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        m=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=3;k++){
                cin>>a[j][k];
            }
        }
        if(n==2){
            n=0;
            for(int k=1;k<=2;k++){
                for(int j=1;j<=3;j++){
                    if(a[k][j]>l){
                        l=a[k][j];
                        mn=j;
                    }
                }
                if(mn==1){
                    se=vv;
                    vv=max(a[k][2],a[k][3]);
                    og[k]=l-vv;
                }
                if(mn==2){
                    se=vv;
                    vv=max(a[k][1],a[k][3]);
                    og[k]=l-vv;
                }
                if(mn==3){
                    se=vv;
                    vv=max(a[k][2],a[k][1]);
                    og[k]=l-vv;
                }
                qw[k]=l;
                l=-1;
            }
            if(og[1]>og[2]){
                cout<<qw[2]+se;
            }
            else{
                cout<<qw[1]+vv;
            }
        }
        for(int j=1;j<=n;j++){
            s[j]=-1;
            int b[4]={0,0,0,0};
            for(int k=1;k<=3;k++){
                if(a[j][k]>s[j]){
                    if(b[k]>=n/2){
                        if(max(a[j][1],a[j][2])<=a[j][k]){
                            int o=20001;
                            for(int r=1;r<=j;r++){
                                if(c[r]==k&&a[r][k]<o){
                                    o=a[r][k];
                                    l=r;
                                }
                            }
                            if(k==1){
                                if(b[2]+1<=n/2&&b[3]+1<=n/2){
                                    m-=a[l][1];
                                    m+=max(a[l][2],a[l][3]);
                                    if(a[l][2]>a[l][3]){
                                        m+=a[j][2];
                                        c[l]=2;
                                    }
                                    else{
                                        m+=a[j][3];
                                        c[l]=3;
                                    }
                                }
                                else if(b[2]==n/2){
                                    m+=a[j][3];
                                    c[l]=3;
                                }
                                else{
                                    m+=a[j][2];
                                    c[l]=2;
                                }
                            }
                            else if(k==2){
                                m-=a[l][2];
                                m+=max(a[l][1],a[l][3]);
                                if(b[1]+1<=n/2&&b[3]+1<=n/2){
                                    if(a[l][1]>a[l][3]){
                                        m+=a[j][1];
                                        c[l]=1;
                                    }
                                    else{
                                        m+=a[j][3];
                                        c[l]=3;
                                    }
                                }
                                else if(b[1]==n/2){
                                    m+=a[j][3];
                                    c[l]=3;
                                }
                                else{
                                    m+=a[j][1];
                                    c[l]=1;
                                }
                            }
                            else if(k==3){
                                m-=a[l][3];
                                m+=max(a[l][2],a[l][1]);
                                if(b[2]+1<=n/2&&b[1]+1<=n/2){
                                    if(a[l][2]>a[l][1]){
                                        m+=a[j][2];
                                        c[l]=2;
                                    }
                                    else{
                                        m+=a[j][1];
                                        c[l]=1;
                                    }
                                }
                                else if(b[1]==n/2){
                                    m+=a[j][2];
                                    c[l]=2;
                                }
                                else{
                                    m+=a[j][2];
                                    c[l]=2;
                                }
                            }
                        }
                    }
                    else{
                        s[j]=a[j][k];
                        b[k]++;
                        c[j]=k;
                    }

                }
            }
            m+=s[j];
        }
        cout<<m;
    }
    return 0;
}
