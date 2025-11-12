#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int sum;
struct node{
    int l,r;
}aa[10000005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int dex=1,flag=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            flag=0;
            int num=a[i];
            for(int x=i+1;x<=j;x++){
                num=num^a[x];
            }
            if(num==k){
                int le=i,re=j;
                for(int de=1;de<=dex;de++){
                    if(le<=aa[de].r){
                        flag=1;
                    }
                }
                if(flag==1) continue;
                else{
                    aa[dex].l=le;
                    aa[dex].r=re;
                    dex++;
                    sum++;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
