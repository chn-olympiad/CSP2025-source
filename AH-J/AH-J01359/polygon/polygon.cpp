#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,f=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)f=1;
    }
    if(n==3){
        int sum=0,maxn=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            maxn=max(maxn,a[i]);
        }
        if(sum>2*maxn){
            cout<<1;
        }
        else cout<<0;
    }
    else if(f==0){
        int sum=0;
        int c=n-2;
        for(int i=1;i<=n-2;i++){
            sum+=i*c;
            c--;

        }
        cout<<sum;
    }
    else{
        long long sum=1;
        for(int i=1;i<=n-2;i++){
            sum*=i;
        }
        cout<<sum;
    }
return 0;}
