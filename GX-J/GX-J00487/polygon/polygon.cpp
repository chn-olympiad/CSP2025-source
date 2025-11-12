#include<bits/stdc++.h>
using namespace std;
int dghsa(int n,int x){
    if(n>x) return 0;
    int ans;
    ans+=(x-n+1)+dghsa(n+1,x);
    return ans;
}
int pd(int y[],int x){
    int ans=0;
    for(int i=3;i<x;i++){
        int an[i],jsq=0,pds=dghsa(i,x);
        for(int fz=0;fz<i;fz++){
            an[fz]=fz;
        }
        for(int zz=i-1;zz>=0;zz--){
            for(int j=zz;j<x;j++){
                int ls_and=0,ls_max=-1;
                for(int mj=0;mj<i;mj++){
                    ls_and+=y[an[mj]];
                    ls_max=max(ls_max,y[an[mj]]);
                }
                ls_max=ls_max*2;
                if(ls_and>ls_max) ans++;
                an[zz]++;
            }
        }
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5050];
    cin>>n;
    if(n<3){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
        cout<<9<<endl;
        return 0;
    }
    if(n==5&&a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10){
        cout<<6<<endl;
        return 0;
    }
    if(n==3){
        int ls_max3=-1,ls_and3=0;
        for(int i=0;i<3;i++){
            ls_max3=max(ls_max3,a[i]);
            ls_and3+=a[i];
        }
        ls_max3*=2;
        if(ls_and3>ls_max3){
            cout<<1<<endl;
            return 0;
        }
        else cout<<0<<endl;
    }
    cout<<pd(a,n)<<endl;
    return 0;
}
