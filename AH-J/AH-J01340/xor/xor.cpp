#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
}b[12000000];
bool cmp(node x,node y){
    if(x.l!=y.l){
        return x.r<y.r;
    }
    return x.l<y.l;
}
int n,k,a[1200000],c[1200000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=c[i-1]^a[i];
    }
    long long cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i==0||j==0){
                continue;
            }
			int h=c[j]^c[i-1];
            if(k==h){
                cnt++;
                b[cnt].l=i,b[cnt].r=j;
            }
        }
    }
    sort(b+1,b+cnt+1,cmp);
    int last=0,ans=0;
    for(int i=1;i<=cnt;i++){
        if(b[i].l>last){
            ans++;
            last=b[i].r;
        }
    }
    cout<<ans;
	return 0;
}
