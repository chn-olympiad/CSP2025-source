#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
struct abc{
    int s,e;
}p[maxn];
int n,k,k1,ans;
int a[maxn];
bool f[maxn];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==k){
            f[i]=1;ans++;
        }
    }
    for(int i=1;i<n;i++){
        int sum=a[i];
        if(f[i]) continue;
        for(int j=i-1;j>=0;j--){
            if(f[j]) break;
            sum=sum^a[j];
//            cout<<j<<" "<<i<<endl;
            if(sum==k){
                p[k1].s=j;p[k1++].e=i;
                break;
            }
        }
    }
//    cout<<endl;
    int en=-1;
    for(int i=0;i<k1;i++){
//        cout<<p[i].s<<" "<<p[i].e<<endl;
        if(p[i].s>en){
            ans++;
            en=p[i].e;
        }
    }
    cout<<ans;
    return 0;
}
