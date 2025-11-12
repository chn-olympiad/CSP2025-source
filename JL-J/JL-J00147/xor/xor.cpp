#include<bits/stdc++.h>
using namespace std;
int n,sam,k;
int a[1000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    sam=0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                sam++;
            }
            else if(a[i]==a[i+1]){
                i++;
                sam++;
            }
        }
    }
    else {
        for(int i=1;i<=n;i++){
            if(a[i]==k){
                sam++;
            }
        }
    }
    printf("%d",sam);
    return 0;
}
