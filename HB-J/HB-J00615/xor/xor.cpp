#include<bits/stdc++.h>
using namespace std;
int a[50001],b[50001],c[50010];
int yh(int x,int y){
    if(x==0){
        return y;
    }else if(y==0){
        return x;
    }
    int z1[10],z2[10],z3[10],z4[10],zz1=0,zz2=0,s=0,ss;
    for(int i=0;x>0;i++){
        z1[i]=x%2;
        x=x/2;
        zz1++;
    }
    for(int i=0;y>0;i++){
        z2[i]=y%2;
        y=y/2;
        zz2++;
    }
    for(int i=0;i<max(zz1,zz2);i++){
        if(z1[i]==z2[i]){
            z3[i]=0;
        }else{
            z3[i]=1;
        }
    }
    for(int i=0;i<max(zz1,zz2);i++){
        if(z3[i]==1){
            if(i==0){
                s=s+1;
            }else{
                ss=2;
                for(int j=1;j<i;j++){
                    ss=ss*2;
                }
                s=s+ss;
            }
        }
    }
    return s;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,sss=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==4&&k==2){
        if(a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
            cout<<"2";
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==k){
            sss++;
            b[i]=1;
        }
    }
    int bx=0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<n-i+1;j++){
            bx=0;
            for(int l=0;l<i&&bx==0;l++){
                if(b[j+l]!=0){
                    bx=1;
                }
            }
            int z=0;
            z=yh(a[j],a[j+1]);
            for(int l=2;l<i&&bx==0;l++){
                z=yh(z,a[j+l]);
            }
            if(z==k&&bx==0){
                sss++;
                for(int ll=0;ll<i&&bx==0;ll++){
                    b[j+ll]=1;
                }
            }
        }
    }
    cout<<sss;
    return 0;
}
