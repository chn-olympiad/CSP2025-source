#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],b[5005],c[5005];
long long ans=0,cnt=0,maxn=-1;
bool x[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b+1,b+1+n);
    for(int j=3;j<=n;j++){
        memset(x,1,sizeof(x));
        for(int k=1;k<=j;k++){
            x[k]=0;
        }
    do{
        maxn=-1;
        long long s=0,h=1;
        for(int i=1;i<=n;i++){
            if(x[i]==0){
                    s=s+b[i];
                    if(b[i]>maxn)
                        maxn=b[i];
            }
        }

        if(s>maxn*2){
            cnt++;
        }

    }while(next_permutation(x+1,x+1+n));

    }
    cout<<cnt<<endl;
    return 0;
}
