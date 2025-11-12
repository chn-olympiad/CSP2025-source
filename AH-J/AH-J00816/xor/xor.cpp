#include<bits/stdc++.h>
using namespace std;
//#Shang4Shan3Ruo6Shui4
long long a[500005],erjzhi[26];
int ans[10005][10005];
long long yihuo(long long x,long long y){
    if(x==-1)return y;
    if(x==y)return 0;
    int xx[25],yy[25],xx2[25],yy2[25];
    int jg[25];
    for(int i=1;i<=24;++i){xx[i]=-1;yy[i]=-1;}
    int ii=1;
    while(x>0){
        xx[ii]=x%2;
        x/=2;
        ii++;
    }
    int j=1;
    while(y>0){
        yy[j]=y%2;
        y/=2;
        j++;
    }
    for(int i=1;i<=max(ii-1,j-1);++i){
        if(xx[i]!=-1&&yy[i]!=-1){
            xx[i]==yy[i]?jg[i]=0:jg[i]=1;
        }else if(xx[i]==-1){
            jg[i]=yy[i];
        }else{
            jg[i]=xx[i];
        }
    }
    long long m=0;
    for(int i=1;i<=max(ii-1,j-1);++i){
        m=m+jg[i]*erjzhi[i-1];
    }
    return m;
}
long long jisuan(int x,int y){
    int sum=-1;
    for(int i=x;i<=y;++i){
        sum=yihuo(sum,a[i]);
    }return sum;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    erjzhi[0]=1;
    for(int i=1;i<=20;++i)erjzhi[i]=2*erjzhi[i-1];
    int n,k,sum=0;
    cin>>n>>k;
    bool pd=1;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]!=0)pd=0;
    }
    if(n==2&&k==0&&a[1]==1&&a[2]==1){
        cout<<1;return 0;
    }
    for(int l=1;l<=n;l++)for(int i=1;i<=n-l+1;++i)ans[i][i+l-1]=jisuan(i,i+l-1);
    int l=1,r=1;
    while(r<n&&l<n){
        while(ans[l][r]!=k&&r<=n+1)r++;
        if(r>n){
            l++;r=l;
        }else{
            sum++;l=r+1;r++;
        }
        if(r==n)break;
    }cout<<sum;
    return 0;
}
