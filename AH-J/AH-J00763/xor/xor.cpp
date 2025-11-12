#include<bits/stdc++.h>
using namespace std;
int a[500005];
int v[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        v[i]=v[i-1]^a[i];
    }
    int sum=0;
    for(int l=1,r=1;r<=n&&l<=n;r++){
        int t=v[l-1]^v[r];
        if(t==k){
            l=r+1;
            sum++;
        }
    }
    cout<<sum;
return 0;
}
//#Shang4Shan3Ruo6Shui4
