#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,cnt,a[N];
int check(int l,int r){
    int tmp=0;
    for(int i=l;i<=r;i++){
        tmp=tmp^a[i];
    }
    return tmp;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=1,r=1,ll=0,lr=0;
    while(l<=n){
        if(check(l,r)==k){
            cnt++;
            if((l>=ll&&r<=lr)||(l<=lr&&r>=ll)) cnt--;
            else ll=l,lr=r;
            l++;
            r=l;
        }else{
            r++;
            if(r==n+1){
                l++;
                r=l;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
