#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5e5+10;
int a[N];
int k;
int sum=0;
int _xor(int l,int r){
    int s=0;
    for(int i=l;i<=r;i++){
        s=s^a[i];
    }
    return s;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int r=0;
    for(int i=0;i<n;i++){
        for(int j=r+1;j<=n-i;j++){
            if(k==_xor(j,j+i)){
                sum++;
                r=j+i;
                //cout<<r<<endl;
            }
            if(j<=r){
                continue;
            }
        }
    }
    printf("%d",sum);
    return 0;
}
