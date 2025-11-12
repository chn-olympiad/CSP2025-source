#include<iostream>
#include<cstdio>
using namespace std;
int n,a[500005],x[500005],l,r,k,cnt,maxn=-0x3f3f3f3f;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x[i]=x[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        l=r=i;
        cnt=0;
        while(r<=n){
            while((x[r]^x[l-1])!=k&&r<n){
                r++;
            }
            if((x[r]^x[l-1])==k){
                if(r!=n){
                    cnt++;
                    l=r+1;
                    r++;
                }else{
                    cnt++;
                    break;
                }
            }else{
                break;
            }
        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
