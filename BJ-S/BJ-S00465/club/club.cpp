#include<bits/stdc++.h>
using namespace std;
int a,b,mmax=-1001,c,diyi=0,dier=0,disan=0,ans=0;
int shetuan1=1,shetuan2=2,shetuan3=3;
int a1[10000][10],q[100001];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>a;
    while(a--){
        cin>>b;
        for(int i=1;i<=b;i++){
            cin>>a1[i][1]>>a1[i][2]>>a1[i][3];
            for(int ii=1;ii<=3;ii++){
                mmax=max(mmax,a1[i][ii]);
                q[i]=mmax;
            }
            for(int j=1;j<=3;j++){
                if(a1[i][j]==q[i]){
                    c=j;
                }
            }
                if(c=shetuan1){
                        mmax=-1001;
                if(diyi<b/2){
                    mmax=-1001;
                ans+=q[i];
                diyi++;
                continue;
                }
                else if(diyi>b/2){
                        mmax=-1001;
                    for(int ii=1;ii<=3;ii++){
                        if(a1[i][ii]=q[i]){
                            a1[i][ii]=0;
                        }
                    }
                    for(int ii=1;ii<=3;ii++){
                        mmax=max(mmax,a1[i][ii]);
                        q[i]=mmax;
                    }
                    for(int j=1;j<=3;j++){
                        if(a1[i][j]=q[i]){
                            c=j;
                        }
                    }
                    if(c=shetuan2&&dier<b/2){
                        ans+=q[i];
                        dier++;
                        continue;
                    }
                    else{
                        ans+=q[i];
                        disan++;
                        continue;
                    }
                }
            }
            if(c=shetuan2&&dier<b/2){
                    mmax=-1001;
                if(dier<=b/2){
                ans+=q[i];
                dier++;
                continue;
                }
                else if(dier>b/2){
                    mmax=-1001;
                    for(int ii=1;ii<=3;ii++){
                        if(a1[i][ii]=q[i]){
                            a1[i][ii]=0;
                        }
                    }
                    for(int ii=1;ii<=3;ii++){
                        mmax=max(mmax,a1[i][ii]);
                        q[i]=mmax;
            mmax=-1001;
                    }
                    for(int j=1;j<=3;j++){
                            mmax=-1001;
                        if(a1[i][j]=q[i]){
                            c=j;
                        }
                    }
                    if(c=shetuan1&&diyi<b/2){
                        ans+=q[i];
                        diyi++;
                        continue;
                    mmax=-1001;
                    }
                    else{
                        ans+=q[i];
                        disan++;
                        mmax=-1001;
                        continue;
                    }
                }
            }
            if(c=shetuan1&&disan<b/2){
                    mmax=-1001;
                if(disan<=b/2){
                ans+=q[i];
                disan++;
                continue;
                }
                else if(disan>b/2){
                    for(int ii=1;ii<=3;ii++){
                        mmax=-1001;
                        if(a1[i][ii]=q[i]){
                            a1[i][ii]=0;
                        }
                    }
                    for(int ii=1;ii<=3;ii++){
                        mmax=-1001;
                        mmax=max(mmax,a1[i][ii]);
                        q[i]=mmax;
                    }
                    for(int j=1;j<=3;j++){
                        if(a1[i][j]=q[i]){
                            mmax=-1001;
                            c=j;
                        }
                    }
                    if(c=shetuan1&&disan<b/2){
                        ans+=q[i];
                        diyi++;
                        continue;
                    }
                    else{
                        ans+=q[i];
                        dier++;
                        continue;
                    }
                }
            }
        }
    cout<<ans<<endl;
    diyi=0,dier=0,disan=0,ans=0;
    }
}

