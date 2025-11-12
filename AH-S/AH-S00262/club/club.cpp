#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int T,n;
int a[maxn][4];
int mx1[maxn],mx2[maxn],mx3[maxn];
int cnt[4];
int ans;
bool check(int u){
    int cnt1 = 0;
    int sum1 = 0;
    int flag = 0;
    for(int i = 1;i<=3;i++){
        cnt1 = 1;
        while(cnt1<n/2){
            if(i == 1){
                sum1+=mx1[cnt[1]-cnt1+1];
                cnt1++;
            }
            if(i == 2){
                sum1+=mx2[cnt[2]-cnt1+1];
                cnt1++;
            }
            if(i == 3){
                sum1+=mx3[cnt[3]-cnt1+1];
                cnt1++;
            }
            if(sum1>u){
                return false;
            }
        }
    }
}
void er_fen(int l,int r){
    if(l == r){
        ans = l;
        return;
    }
    int mid = (l+r)>>1;
    if(!check(mid)){
        er_fen(mid+1,r);
    }else{
        er_fen(l,mid);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    int sum = 0;
    while(T--){
        cin>>n;
        int f = 0;
        int f1 = 0;
        for(int i = 1;i<=n;i++){
            f = 0;
            f1 = 0;
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            for(int j = 1;j<=3;j++){
               if(a[i][j]>f){
                    f = a[i][j];
                    f1 = j;
               }
            }
            if(f1 == 1){
                mx1[cnt[f1]+1] = f;
                cnt[f1]++;
            }
            if(f1 == 2){
                mx2[cnt[f1]+1] = f;
                cnt[f1]++;
            }
            if(f1 == 3){
                mx3[cnt[f1]+1] = f;
                cnt[f1]++;
            }
            //mx[cnt[f1]+1][f1] = f;
            //cout<<f<<f1;
            cnt[f1]++;
            sum+=f;
        }
        sort(mx1+1,mx1+cnt[1]+1);
        sort(mx2+1,mx2+cnt[2]+1);
        sort(mx3+1,mx3+cnt[3]+1);
        er_fen(1,sum);
        cout<<ans<<endl;
    }
    return 0;
}
