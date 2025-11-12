#include<bits/stdc++.h>
using namespace std;
int n,t,a[10000][10000],b[3],ans[5],q,w,e,s,x[10000];
int main(){
    cin>>t;
    for(int p=1;p<=t;p++){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        if(n==2){
            int qq[10]={0};
            qq[2]=a[1][2]+a[2][1];
            qq[3]=a[1][3]+a[2][1];
            qq[4]=a[1][1]+a[2][2];
            qq[6]=a[1][3]+a[2][2];
            qq[7]=a[1][1]+a[2][3];
            qq[8]=a[1][2]+a[2][3];
            sort(qq,qq+10);
            ans[t]=qq[9];
            continue;
        }
       int l;
       for(int i=1;i<=n;i++){
           if(a[n][2]==a[n][3]&&a[n][2]==0){
                l=1;
            }else{
                l=0;
            }
        }
        if(l==1){
                int m=0;
            for(int i=1;i<=n;i++){
                x[i]=a[i][1];
            }
            sort(x,x+n+1);
            for(int i=n;i>n/2;i--){
                m+=x[i];
            }
            ans[p]=m;
            continue;
        }



        b[1]=a[1][1];
        b[2]=a[1][2];
        b[3]=a[1][3];
        if(q<+n/2 && w<=n/2 && e<=n/2){
            for(int i=1;i<=3;i++){
                for(int j=1;j<=n;j++){
                    if(a[j][i]>b[i]){
                        b[i]=a[j][i];
                    }
                }
                for(int j=1;j<=n;j++){
                    if(a[j][i]==b[i]){
                       a[j][i]==0;
                    }
                }
                ans[p]+=b[i];
                if(i==1){
                    q++;
                }else if(i==2){
                    w++;
                }else{
                    e++;
                }
            }
        }
        n=0;
    }

    for(int p=1;p<=t;p++){
        cout<<ans[p]<<" "<<endl;
    }
    return 0;
}
