#include<bits/stdc++.h>
    using namespace std;
    int a[100010][5],d1[100010],d2[100010],d3[100010];
    long long k[25];
    int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k,x,sum=0,mi=10000000000000,ma1=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    long long nh,df,x;
    scanf("%lld %lld %lld",&nh,&df,&x);
    if(nh!=df)sum+=x;
    }
    for(int i=1;i<=k;i++){
		ma1=0;
    long long asd;
    cin>>asd;
    ma1+=asd;
    for(int i=1;i<=n;i++){
    cin>>x;
    ma1+=x;
    }
    mi=min(mi,ma1);
    }
    if(k==0){
    cout<<sum;
    }
    else{
    cout<<mi;
    }
    return 0;
    }
