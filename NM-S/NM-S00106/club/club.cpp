#include <bits/stdc++.h>

using namespace std;
struct yg{
    int a,b,c;
};
int main () {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int ma,mb;
    int t,x,m,p,flag,plag;
    int n;
    int N[3][100005];
    yg pp[100005];
    cin>>t;
    for(int i=0;i<t;i++){
        int ans=0;
        for(int o=0;o<3;o++){
            N[o][100005]={0};
        }
        int a=0,b=0,c=0;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>pp[j].a>>pp[j].b>>pp[j].c;

        }

        for(int j=1;j<=n;j++){
            for(int k=0;k<j;k++){
                x=max(pp[k].a,pp[k].b);
                x=max(x,pp[k].c);
                m=max(pp[k+1].a,pp[k+1].b);
                m=max(m,pp[k+1].c);
                if(x<m){
                    swap(pp[k],pp[k+1]);
                        }
                }
        }
        for(int j=0;j<n;j++){

            int f=1,ma=0,mb=0;
            if(pp[j].b>pp[j].a){
                if(pp[j].c>pp[j].b) f=3;
                else f=2;
            }
            else if(pp[j].c>pp[j].a) f=3;
            if(f==1){
                if(a<n/2){
                    a++;
                    N[f][a]=j;
                }
                else{
                    flag=-1,plag=0;
                    for(int y=a;y>0;y--){
                        int z=N[f][y];
                        if(pp[z].b>pp[z].c){
                            ma=pp[z].b;
                            mb=2;
                        }
                        else {
                            ma=pp[z].c;
                            mb=3;
                        }
                        if(plag<ma+pp[j].a-pp[z].a){
                           plag=ma+pp[j].a-pp[z].a;
                           flag=y;
                        }
                    }
                    if(flag>=0){
                        a++;
                        N[f][a]=j;
                        N[f][flag]=-1;
                        if(pp[flag].b>pp[flag].c){
                            b++;
                            N[2][b]=flag;
                        }
                        else {
                            c++;
                            N[2][c]=flag;
                        }
                    }
                    else{
                        if(pp[j].b>pp[j].c){
                            b++;
                            N[2][b]=j;
                        }
                        else {
                            c++;
                            N[2][c]=j;
                        }
                    }
                }
            }
            if(f==2){
                if(b<n/2){
                    b++;

                    N[f][b]=j;
                }
                else{
                    flag=-1,plag=0;
                    for(int y=b;y>0;y--){
                        int z=N[f][y];
                        if(pp[z].a>pp[z].c){
                            ma=pp[z].a;
                        }
                        else {
                            ma=pp[z].c;
                        }
                        if(plag<ma+pp[j].b-pp[z].b){
                           plag=ma+pp[j].b-pp[z].b;
                           flag=y;
                        }
                    }
                    if(flag>=0){
                        b++;
                        N[f][b]=j;
                        N[f][flag]=-1;
                        if(pp[flag].a>pp[flag].c){
                            a++;
                            N[2][a]=flag;
                        }
                        else {
                            c++;
                            N[2][c]=flag;
                        }
                    }
                    else{
                        if(pp[j].a>pp[j].c){
                            a++;
                            N[2][a]=j;
                        }
                        else {
                            c++;
                            N[2][c]=j;
                        }
                    }
                }
            }
            if(f==3){
                if(c<n/2){
                    c++;
                    N[f][c]=j;
                }
                else{

                    flag=-1,plag=0;
                    for(int y=c;y>0;y--){
                        int z=N[f][y];
                        if(pp[z].a>pp[z].b){
                            ma=pp[z].a;
                        }
                        else {
                            ma=pp[z].b;
                        }
                        if(plag<ma+pp[j].c-pp[z].c){
                           plag=ma+pp[j].c-pp[z].c;
                           flag=y;
                        }
                    }
                    if(flag>=0){
                        c++;
                        N[f][c]=j;
                        N[f][flag]=-1;
                        if(pp[flag].a>pp[flag].b){
                            a++;
                            N[2][a]=flag;
                        }
                        else {
                            b++;
                            N[2][b]=flag;
                        }
                    }
                    else{
                        if(pp[j].a>pp[j].b){
                            a++;
                            N[2][a]=j;
                        }
                        else {
                            b++;
                            N[2][b]=j;
                        }
                    }
                }
            }

        }
        for(int j=1;j<=a;j++){
            if(N[1][j]>=0)ans+=pp[N[1][j]].a;
        }
        for(int j=1;j<=b;j++){
            if(N[2][j]>=0)ans+=pp[N[2][j]].b;
        }
        for(int j=1;j<c;j++){
            if(N[3][j]>=0)ans+=pp[N[3][j]].c;
        }
        cout<<ans<<endl;

    }

    return 0;
}
