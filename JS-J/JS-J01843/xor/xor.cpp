#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int left1[1000005];
int right1[1000005];
int answer[1000005];
int n,k;
int pos,posk;
struct l{
    int l,r,k;
}m[1000005];
bool cmp(l a,l b){
    return a.r<b.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n<=10000){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            left1[pos+1]=i;
            right1[pos+1]=i;
            answer[++pos]=a[i];
            for(int j=i+1;j<=n;j++){
                left1[pos+1]=i;
                right1[pos+1]=j;
                answer[pos+1]=(answer[pos]^a[j]);
                ++pos;
            }
        }
        for(int i=1;i<=pos;i++){
            if(answer[i]==k){
                m[posk+1].l=left1[i];
                m[posk+1].r=right1[i];
                m[++posk].k=answer[i];
            }
        }
        sort(m+1,m+posk+1,cmp);
        long long cnt=0;
        int pre=0;
        for(int i=1;i<=posk;i++){
            if(m[i].l>pre){
                pre=m[i].r;
                cnt++;
            }
        }
        cout<<cnt;
    }
    else{
        if(k==0){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0)
                    cnt++;
            }
            cout<<cnt;
        }
        else{
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1)
                    cnt++;
            }
            cout<<cnt;
        }
    }
    return 0;
}
