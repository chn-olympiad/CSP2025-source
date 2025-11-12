#include<bits/stdc++.h>
#define lxx 0
using namespace std;
int w[1005];
bool bok[1005];
struct node{
    int l;
    int r;
    int lon;
}a[10005];
bool cmp(node x,node y){
    return x.lon<y.lon;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    int cnt=0;
    cin>>n>>k;
    int cnt0=0,cnt1=0;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        if(w[i]==1) cnt1++;
        else if(w[i]==0) cnt0++;
        else flag=0;
    }
    if(flag==1 && cnt0==0){
        cout<<n/2;
        return lxx;
    }else if(flag==1 && cnt0!=0){
        if(k==0) cout<<cnt1/2+cnt0;
        else cout<<cnt1;
        return lxx;
    }
    int t=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int ans=w[i];
            if(i==j){
                if(ans==k){
                    a[t].l=i;
                    a[t].r=i;
                    a[t].lon=1;
                    t++;
                    continue;
                }
            }
            for(int l=i+1;l<=j;l++){
                ans=ans xor w[l];
            }
            if(ans==k){
                a[t].l=i;
                a[t].r=j;
                a[t].lon=j-i+1;
                t++;
            }
        }
    }
    sort(a+1,a+t,cmp);
    for(int i=1;i<t;i++){
        // cout<<a[i].l<<" "<<a[i].r<<endl;
        int flag=1;
        for(int j=a[i].l;j<=a[i].r;j++){
            if(bok[j]==1){
                flag=0;
                break;
            }
        }
        if(flag){
            // cout<<a[i].l<<" "<<a[i].r<<endl;
            for(int j=a[i].l;j<=a[i].r;j++){
                bok[j]=1;
            }
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    return lxx;
}