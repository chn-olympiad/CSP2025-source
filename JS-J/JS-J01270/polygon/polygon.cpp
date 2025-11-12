#include<bits/stdc++.h>
using namespace std;

int n;
int a[5050];
bool used_dfs[5051];
int cnt=0;
long long ans=0;

void dfs(int i,int leng,int deep,int big){

    if(deep==i){
        int kkksc03=0,maxx=-1;
        for(int k=1;k<=big;k++){
            if(used_dfs[k]==1)kkksc03+=a[k];
            if(a[k]>maxx&&used_dfs[k]==1)maxx=a[k];
        }
        if(kkksc03>2*maxx)ans++;
        return;
    }

    int bigg=big;

    for(int l=big;l<=leng;l++){
        if(used_dfs[l]==0){
            used_dfs[l]=1;
            big=l;
            dfs(i,leng,deep+1,big);
            big=bigg;
            used_dfs[l]=0;
        }
    }

    return;
}

int main(){

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;

    if(n==3){

        int a,b,c;
        cin>>a>>b>>c;

        if(a+b+c>2*max(max(a,b),c))cout<<1<<endl;
        else cout<<0<<endl;

        return 0;
    }

    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=3;i<=n;i++){dfs(i,n,0,1);}

    cout<<ans<<endl;

    return 0;
}
//1h, 40+floor(rand()*4)pts maybe :)

//In all 250pts I suppose:)
