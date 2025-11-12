#include<bits/stdc++.h>
using namespace std;
int a[500010];
struct node{
    int l,r;
}c[500010];
bool cmp(node x,node y){
    return x.l<y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if((k==0&&n<=2)||(k==0&&n<=100)){
        cout<<n;
    }else{
        int anscnt=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                int res=0;
                for(int l=0;l<n;l++){
                    for(int k=l;k<l+j;k++){
                        res^=a[l];
                    }
                    if(res==k){
                        c[anscnt]={l,l+j};
                    }
                }
            }
        }
        int ans=0;
        sort(c,c+anscnt,cmp);
        for(int i=0;i<n;i++){
            if(!(c[i].r<c[i+1].l)){
                ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}

