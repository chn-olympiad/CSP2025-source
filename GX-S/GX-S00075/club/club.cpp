#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int EX_i;
int a[4][100010];
int del[4][100010];
int dl[100010];
int id[1000010];
int cnt[4];
long long ans;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<=n;j++){
                dl[j]=0x3fffffff;
            }
            cnt[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>a[1][i]>>a[2][i]>>a[3][i];
        }
        for(int i=1;i<=n;i++){
            if(a[1][i]>a[2][i]){
                if(a[1][i]>a[3][i]){
                    cnt[1]++;
                    ans+=a[1][i];
                    id[i]=1;
                }
                else{
                    cnt[3]++;
                    ans+=a[3][i];
                    id[i]=3;
                }
            }
            else{
                if(a[2][i]>a[3][i]){
                    cnt[2]++;
                    ans+=a[2][i];
                    id[i]=2;
                }
                else{
                    cnt[3]++;
                    ans+=a[3][i];
                    id[i]=3;
                }
            }
        }
        for(int k=1;k<=3;k++){
            if(cnt[k]>n/2){
                EX_i=k;
                for(int i=1;i<=n;i++){
                    if(id[i]==k){
                        for(int j=1;j<=3;j++){
                            del[j][i]=a[k][i]-a[j][i];
                            if(j!=k) dl[i]=min(dl[i],del[j][i]);
                        }
                    }
                }
            }
        }
        sort(dl+1,dl+1+n,cmp);
        for(int i=1;i<=cnt[EX_i]-n/2;i++){
            ans-=dl[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
