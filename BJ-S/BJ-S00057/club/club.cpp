#include<bits/stdc++.h>
using namespace std;
int n,buzd,sum=0;
int  a[10005][3];
int  b[10005][3];
int c[10005][3];
int flag1=0;
long long  ans=0;
int main(){
    freopen ("club.in","r",stdin);
    freopen ("club.out", "w",stdout);

    int t;
    cin>>t;
    while (t--){
        ans=0;
        cin>>n;
        buzd=n/2;
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][0]>a[i][1]){
                if(a[i][0]==a[i][1]){
                    if(a[i][1]>a[i][2]){
                        b[i][0]=2;
                        b[i][1]=2;
                        b[i][2]=0;
                    }
                     else if (a[i][1]<a[i][2]){
                        b[i][0]=1;
                        b[i][1]=1;
                        b[i][2]=2;
                     }else {
                         b[i][0]=2;
                        b[i][1]=2;
                        b[i][2]=2;
                     }
                }
                else if(a[i][0]>a[i][2]) {
                        if(a[i][1]<a[i][2]){
                             b[i][0]=2;
                    b[i][1]=0;
                    b[i][2]=1;
                        }if(a[i][1]==a[i][2]){
                             b[i][0]=2;
                    b[i][1]=1;
                    b[i][2]=1;
                        }if(a[i][1]>a[i][2]){
                             b[i][0]=2;
                    b[i][1]=1;
                    b[i][2]=0;
                        }

                }else if (a[i][0]==a[i][2]){
                    b[i][0]=2;
                    b[i][1]=0;
                    b[i][2]=2;
                }else {
                    b[i][0]=1;
                    b[i][1]=0;
                    b[i][2]=2;
                }

            }
            else if(a[i][0]<a[i][2]) {
                    if(a[i][1]>a[i][2]){
                    b[i][0]=0;
                    b[i][1]=2;
                    b[i][2]=1;
                    }
                    else if(a[i][1]==a[i][2]){
                    b[i][0]=0;
                    b[i][1]=2;
                    b[i][2]=2;
                    }else{
                    b[i][0]=0;
                    b[i][1]=1;
                    b[i][2]=2;
                    }
                }else if (a[i][0]==a[i][2]){
                    b[i][0]=1;
                    b[i][1]=2;
                    b[i][2]=1;
                }else {
                    b[i][0]=1;
                    b[i][1]=2;
                    b[i][2]=0;
                }

        }
        for(int  i=0;i<3;i++){
                sum=0;
                int chao=0;
                 for(int k=0;k<n;k++){
                            if(b[k][i]==2){
                                if(b[k][1]==1) c[k][i]=a[k][i]-a[k][1];
                                 else if(b[k][2]==1) c[k][i]=a[k][i]-a[k][2];
                                else if(b[k][3]==1) c[k][i]=a[k][i]-a[k][3];
                            }
                        }
            for(int j=0;j<n;j++){
                if(b[j][i]==2) sum++;
            }
            if(sum>buzd) {
                chao=sum-buzd;
                while  (chao--){
                        bool flag=0;
                    for(int k=0;k<n;k++){
                        if(b[k][i]==2){
                            if((b[k][1]==2)&&(b[k][2]==2)||(b[k][1]==2)&&(b[k][3]==2)||(b[k][3]==2)&&(b[k][2]==2)){
                                b[k][i]==0;
                                flag=1;
                                break;
                            }

                        }
                    }
                    if(flag==0) {

                        flag1=0;

                    for(int k=1;k<n;k++){
                        if(c[k][i]<c[flag1][i]) flag1=k;
                    }
                    c[flag1][i]=100000;
                    b[flag1][i]=0;
                    if(b[flag1][1]==1)  b[flag1][1]=2;
                    else if(b[flag1][2]==1) b[flag1][2]=2;
                    else if(b[flag1][3]==1) b[flag1][3]=2;
                    }
                }
            }
        }
    for(int k=0;k<n;k++){
        if((b[k][1]==2)&&(b[k][2]==2)||(b[k][1]==2)&&(b[k][3]==2)||(b[k][3]==2)&&(b[k][2]==2)){
                                if((b[k][1]==2)&&(b[k][2]==2)) b[k][2]==0;
                                if((b[k][1]==2)&&(b[k][3]==2)) b[k][3]==0;
                                if((b[k][1]==2)&&(b[k][3]==2)) b[k][3]==0;
                                }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            if(b[i][j]==2) {ans+=a[i][j];}
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}
