#include<bits/stdc++.h>
using namespace std;
int a[100005];
int u=0;
struct node{
    int l,r,d=0;
}b[100005];
bool cmp(node l1,node l2){
    return l1.d>l2.d;
}
bool mm(){
    for(int i=1;i<=u;i++){
        if(b[i].d>0){
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int k2=0;
        for(int j=i;j>=1;j--){
            k2^=a[j];
            if(k2==k){
                u++;
                b[u].l=j;
                b[u].r=i;
                break;
            }
        }
    }
    for(int i=1;i<=u;i++){
        for(int j=1;j<=u;j++){
            if(i!=j){
                if(b[i].r>=b[j].l&&b[i].r<=b[j].r){
                    b[i].d++;
                }
                else if(b[i].l>=b[j].l&&b[i].l<=b[j].r){
                    b[i].d++;
                }
                else if(b[j].l<=b[i].r&&b[j].l>=b[i].l){
                    b[i].d++;
                }
                else if(b[j].r<=b[i].r&&b[j].r>=b[i].l){
                    b[i].d++;
                }
            }
        }
    }
    for(int i=1;mm()==0;i++){
        sort(b+1,b+1+u,cmp);
        for(int i=2;i<=u;i++){
            b[i-1].l=b[i].l;
            b[i-1].r=b[i].r;
            b[i-1].d=0;
        }
        u--;
        for(int i=1;i<=u;i++){
            for(int j=1;j<=u;j++){
                if(i!=j){
                    if(b[i].r>=b[j].l&&b[i].r<=b[j].r){
                        b[i].d++;
                    }
                    else if(b[i].l>=b[j].l&&b[i].l<=b[j].r){
                        b[i].d++;
                    }
                    else if(b[j].l<=b[i].r&&b[j].l>=b[i].l){
                        b[i].d++;
                    }
                    else if(b[j].r<=b[i].r&&b[j].r>=b[i].l){
                        b[i].d++;
                    }
                }
            }
        }
    }
    cout<<u;
    return 0;
}
