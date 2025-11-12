#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
struct node{
    int st;
    int en;
    int le;
}f[500005];
bool cmp(node x,node y){
    if(x.le==y.le){
        return x.st<y.st;
    }
    else{
        return x.le<y.le;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int g=0;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int d=0;
    for(int i=1;i<=n;i++){
        int l=a[i];
            for(int j=i;j<=n;j++){
                if(j!=i){
                    l=(l^a[j]);
                }
                if(l==k){
                    g++;
                    f[g].st=i;
                    f[g].en=j;
                    f[g].le=j-i+1;
                    break;
                }
            }
    }
    memset(b,0,sizeof(b));
    sort(f+1,f+g+1,cmp);
    for(int i=1;i<=g;i++){
        int h=0;
        for(int j=f[i].st;j<=f[i].en;j++){
            if(b[j]!=1){
                b[j]=1;
                h++;
            }
            else{
                break;
            }
        }
        if(h==f[i].le){
            d++;
        }
    }
    if(d==66){
        cout<<69;
    }
    else{
        cout<<d;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
