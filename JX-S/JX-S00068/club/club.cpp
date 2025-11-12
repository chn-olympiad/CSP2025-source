#include<bits/stdc++.h>
using namespace std;
struct manyi{
    int bm1;
    int bm2;
    int bm3;
};
struct str{
    int id;
    int num;
};
bool cmp(manyi comp1,manyi comp2){
    int li1[3] = {comp1.bm1,comp1.bm2,comp1.bm3};
    int li2[3] = {comp2.bm1,comp2.bm2,comp2.bm3};
    sort(li1,li1+3);
    sort(li2,li2+3);
    if(li1[2]==li2[2]){
        if(li1[1]==li2[1]){
            return li1[0]>li2[0];
        }
        return li1[1]>li2[1];
    }
    return li1[2]>li2[2];
}bool cmp2(str a1,str a2){
    return a1.num>a2.num;
}
manyi mp[100010] = {};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i = 1;i<=n;i++){
            cin>>mp[i].bm1>>mp[i].bm2>>mp[i].bm3;
        }
        sort(mp+1,mp+n+1,cmp);
        if(n<=200){
                //cout<<1;
            int dp[200][100][100] = {};
            for(int i = 1;i<=n;i++){
                for(int l = 0;l<=min(n/2,i);l++){
                    for(int r = 0;r<=min(n/2,i-l);r++){
                        int z = i-l-r;
                        if(z<=n/2){
                            if(l>0){
                                dp[i][l][r] = max(dp[i][l][r],dp[i-1][l-1][r]+mp[i].bm1);
                            }
                            if(r>0){
                                dp[i][l][r] = max(dp[i][l][r],dp[i-1][l][r-1]+mp[i].bm2);
                            }
                            if(z>0){
                                dp[i][l][r] = max(dp[i][l][r],dp[i-1][l][r]+mp[i].bm3);
                            }

                        }
                    }
                }
            }
            int ans = 0;
            for(int l = 0;l<=n/2;l++){
                for(int r = 0;r<=min(n/2,n-l);r++){
                    int z = n-l-r;
                    if(z<n/2){
                        ans = max(dp[n][l][r],ans);
                    }
                }
            }
            cout<<ans<<endl;
        }else{
            int ans = 0;
            int cl[4] = {};
            for(int i = 1;i<=n;i++){
                str listt[4] = {{0,0},{mp[i].bm1,1},{mp[i].bm2,2},{mp[i].bm3,3}};
                sort(listt+1,listt+4,cmp2);

                if(cl[listt[1].id] >= n/2){
                    if(cl[listt[2].id] >= n/2){
                        ans = ans+listt[3].num;
                        cl[listt[3].id]++;
                    }
                    else{
                        ans = ans+listt[2].num;
                        cl[listt[2].id]++;
                    }
                }else{
                    ans = ans+listt[1].num;
                    cl[listt[1].id]++;
                }
            }
            cout<<ans<<endl;
        }
    }
}
