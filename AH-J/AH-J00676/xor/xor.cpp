#include <bits/stdc++.h>
using namespace std;

int n,k,a[500010];
struct posi{
    int l,r;
};
posi pos[500010];
bool px(posi x,posi y){return x.r<y.r;}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    long long ans=0;
    int sum=0,js=0;
    for(int i=1;i<=n;i++){
        if(a[i]==k){js++;pos[js].l=i;pos[js].r=i;}
        sum=a[i];
        for(int j=1;j<=n-i;j++){
            sum^=a[i+j];
            if(sum==k){
                js++;
                pos[js].l=i;
                pos[js].r=i+j;
                break;
            }
        }
    }
    sort(pos+1,pos+js+1,px);
    int lr=-1;
    for(int i=1;i<=js;i++){
        if(pos[i].l>lr){
            ans++;
            lr=pos[i].r;
        }
    }
    cout<<ans<<endl;
    return 0;
}
