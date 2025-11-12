#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt;
struct node{
    int q,z;
}c[500005];
struct str{
    int h,xb;
}b[500005];
int cmp(str a,str b){
    if(a.h!=b.h)return a.h<b.h;
    return a.xb<b.xb;
}
int cmp1(node a,node b){
    if(a.z!=b.z)return a.z<b.z;
    return a.q<b.q;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i].h=b[i-1].h^a[i];
        b[i].xb=i;
    }
    sort(b+1,b+n+1,cmp);
    //for(int i=1;i<=n;i++)cout<<b[i].h<<" "<<b[i].xb<<endl;
    for(int i=1;i<=n;i++){
        int ans=b[i].h^k;
        int l=0,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(b[mid].h==ans){
                if(b[mid].xb>=b[i].xb){
                    r=mid-1;
                    continue;
                }
                c[i].q=b[mid].xb+1,c[i].z=b[i].xb;
                l=mid+1;
            }
            if(b[mid].h<ans){
                l=mid+1;
            }
            if(b[mid].h>ans){
                r=mid-1;
            }
        }
    }
    sort(c+1,c+n+1,cmp1);
    int nowz=0;
    for(int i=1;i<=n;i++){
        if(c[i].q!=0||c[i].z==0){
            //cout<<c[i].q<<" "<<c[i].z<<endl;
            if(c[i].q>nowz){
                //if(c[i].q==c[i].z&&a[c[i].q]!=k)continue;
                nowz=c[i].z;
                cnt++;
                //cout<<c[i].q<<" "<<c[i].z<<endl;
            }
        }
    }
    cout<<cnt;
    return 0;
}