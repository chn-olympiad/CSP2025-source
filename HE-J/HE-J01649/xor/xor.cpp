#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=1e7;
int n,k,a[N],num;
struct E{
    int l,r;
    bool operator<(const E &t){
        if(t.l!=l){
            return t.l>l;
        }
        return t.r>r;
    }
}q[M];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int res=a[i];
        if(res==k){
            q[++num].l=i;
            q[num].r=i;
        }
        for(int j=i+1;j<=n;j++){
            res^=a[j];
            if(res==k){
                num++;
                q[num].l=i;
                q[num].r=j;
            }
        }
    }
    sort(q+1,q+1+num);
    int w=1,res=0;
    for(int i=1;i<=num;i++){
        if(q[i].l>=w){
            w=q[i].r+1;
            res++;
        }
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
