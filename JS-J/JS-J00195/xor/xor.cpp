#include<bits/stdc++.h>
using namespace std;

int k,numb=0;

int yihh(int a, int b){
    int ans=0;
    int d[20],p[20];
    for(int j=20; j>=0; j--){
        int u=pow(2,j);
        d[20-j]=a%u;
        a=a-a%u*u;
    }
    for(int j=20; j>=0; j--){
        int u=pow(2,j);
        p[20-j]=b%u;
        b=b-b%u*u;
    }
    for(int i=0; i<=20; i++){
        if(d[i]%2!=p[i]%2){
            ans=ans*10+1;
        }
        else{
            ans=ans*10;
        }
    }
    return ans;
}

int quan(int a){
    int cnt=0;
    while(a>0){
        if(a%2==1) cnt++;
        a/=10;
    }
    return cnt;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,a;
    cin>>n>>k;
    int num[500010];
    for(int i=0; i<n; i++){
        cin>>a;
        for(int j=20; j>=0; j--){
            int u=pow(2,j);
            num[i]=num[i]*10+a%u;
            a=a-a%u*u;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n-i; j++){
            int x=num[j];
            for(int h=j; h<j+i-1; h++){
                x=yihh(x,num[h+1]);
            }
            if(quan(x)==k) numb+=1;
        }
    }
    cout<<numb;
    return 0;
}
