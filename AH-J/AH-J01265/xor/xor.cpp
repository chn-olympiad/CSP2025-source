#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
long long a[500005],xo2[500005];
bool A=1,B=1,C=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        xo2[i]=xo2[i-1]^a[i];
        if(a[i]!=1) A=0;
        if(a[i]>1) B=0;
        if(a[i]>255) C=0;
    }
    if(A){
        cout<<n/2;
    }else if(B){
        if(!k){
            int cnt=0;
            for(int i=1,j=0;i<=n;i++){
                if(a[i]==0) cnt++;
                if(a[i]==1) j++;
                if(j==2){
                    cnt++;
                    j=0;
                }
            }
            cout<<cnt;
        }else{
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1) cnt++;
            }
            cout<<cnt;
        }
    }else{
        int cnt=0;
        for(int i=1,j=1;i<=n;i++){
            for(int ij=j;ij<=i;ij++){
                if((xo2[i]^xo2[ij-1])==k){
                    cnt++;
                    j=i+1;
                    break;
                }
            }
        }
        cout<<cnt;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
