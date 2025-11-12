#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,a[100005][4],num=0,aa[50005],bb[50005],cc[50005];
        cin>>n;
        int b[50005][4],a1=0,b1=0,c1=0,len=n/2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n-1;i++){
            for(int j=1;j<=n-1;j++){
                if(a[i][1]>a[i+1][1]){
                    swap(a[i][1],a[i+1][1]);
                    swap(a[i][2],a[i+1][2]);
                    swap(a[i][3],a[i+1][3]);
                }else if(a[i][1]==a[i+1][1]){
                    if(a[i][2]>a[i+1][2]){
                        swap(a[i][1],a[i+1][1]);
                        swap(a[i][2],a[i+1][2]);
                        swap(a[i][3],a[i+1][3]);
                    }else if(a[i][2]==a[i+1][2]){
                        if(a[i][3]>a[i+1][3]){
                            swap(a[i][1],a[i+1][1]);
                            swap(a[i][2],a[i+1][2]);
                            swap(a[i][3],a[i+1][3]);
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            int mx=INT_MIN,mxi=0,mx2=INT_MIN,mx2i=0;
            int mx1=INT_MIN,mx1i=0;
            for(int j=1;j<=3;j++){
                if(a[i][j]>mx){
                    mx=a[i][j];
                    mxi=j;
                }
            }
            a[i][mxi]=0;
            for(int j=1;j<=3;j++){
                if(a[i][j]>mx1){
                    mx1=a[i][j];
                    mx1i=j;
                }
            }
            a[i][mx1i]=0;
            for(int j=1;j<=3;j++){
                if(a[i][j]>mx2){
                    mx2=a[i][j];
                    mx2i=j;
                }
            }
            if(mxi==1){
                if(a1+1<=len){
                    num+=mx;
                    a1++;
                }else{
                    if(mx1i==2){
                        if(b1+1<=len){
                            num+=mx1;
                            b1++;
                        }else{
                            if(c1+1<=len){
                                c1++;
                                num+=mx2;
                            }
                        }
                    }else{
                        c1++;
                        num+=mx2;
                    }
                }
            }else if(mxi==2){
                if(b1+1<=len){
                    num+=mx;
                    b1++;
                }else{
                    if(mx1i==1){
                        if(a1+1<=len){
                            num+=mx;
                            a1++;
                        }else{
                            if(c1+1<=len){
                                c1++;
                                num+=mx2;
                            }

                        }
                    }else{
                        c1++;
                        num+=mx2;
                    }
                }
            }else{
                if(c1+1<=len){
                    c1++;
                    num+=mx;
                }else{
                    if(mx1i==1){
                        if(a1+1<=len){
                            num+=mx;
                            a1++;
                        }else{
                            if(b1+1<=len){
                                b1++;
                                num+=mx1;
                            }

                        }
                    }else{
                        b1++;
                        num+=mx1;
                    }
                }
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
