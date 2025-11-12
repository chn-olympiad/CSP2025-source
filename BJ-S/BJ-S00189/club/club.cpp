#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
/*1s 512MB
given array a1,a2,a3 find the most sigma a_di with the most di<=n/2
*/
#define int ll
/*
only the largest and the second-largest matters 
*/
#define mp make_pair
int a[N][3];
int T,n;
struct node{
    signed mx,mx2,mxid,mx2id,id;
    bool operator<(node &A)const{
        return mx-mx2<A.mx-A.mx2;
    }
}f[N];
int cnt[15];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>T;
    while(T--){
        memset(f,0,sizeof f);
        memset(cnt,0,sizeof cnt);
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
        int s=0;
        for(int i=1;i<=n;i++){
            if(a[i][0]>=a[i][1] and a[i][0]>=a[i][2]){
                f[i].mxid=0;
                if(a[i][1]>a[i][2])f[i].mx2id=1;
                else f[i].mx2id=2;
            }
            else if(a[i][1]>=a[i][0] and a[i][1]>=a[i][2]){
                f[i].mxid=1;
                if(a[i][0]>a[i][2])f[i].mx2id=0;
                else f[i].mx2id=2;
            }
            else{
                f[i].mxid=2;
                if(a[i][0]>a[i][1])f[i].mx2id=0;
                else f[i].mx2id=1;
            }
            s+=a[i][f[i].mxid];
            f[i].mx=a[i][f[i].mxid];
            f[i].mx2=a[i][f[i].mx2id];
            cnt[f[i].mxid]++;
            f[i].id=i;
        }
        int p=0;
        if(cnt[1]>cnt[p])p=1;
        if(cnt[2]>cnt[p])p=2;
        if(cnt[p]>n/2){
            sort(f+1,f+1+n);
            for(int i=1;i<=n;i++){
                // cout<<f[i].id<<" ";
                if(f[i].mxid==p){
                    cnt[p]--;
                    cnt[f[i].mx2id]++;
                    s+=(f[i].mx2-f[i].mx);
                    if(cnt[p]<=n/2)break;
                }
            }
        }
        cout<<s<<endl;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}