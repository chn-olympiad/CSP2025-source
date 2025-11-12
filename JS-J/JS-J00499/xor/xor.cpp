#include<cstdio>
#include<iostream>
using namespace std;

int n,k,a[500010];
int vis[500010],res;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    // kongbu de O(n^5)
    for(int i=n;i>=1;i--){ //bianli suoyou qujian geshu
        for(int jj=0;jj<=n+1;jj++) vis[jj] = -1;
        for(int ii=1;ii<=i-1;ii++){ //xunhuan shencheng qujian
            for(int j=1;j<=n-ii;j++){ //qujian kaitou
                for(int kk=j;kk<=n-ii;kk++){ //qujian jiewei
                    bool flag = 0;
                    for(int iii=j;iii<=kk;iii++){ //tianchong qujian bianhao
                        if(vis[iii]==-1){
                            vis[iii] = ii;
                        }
                        else{ //qujian chongdie, zhijie tuichu
                            for(int iiii=j;iiii<=iii;iiii++){ //huanyuan
                                vis[iiii] = -1;
                            }
                            flag = 1;
                        }
                    }
                    if(flag)break;
                    else{ //jisuan
                        int ans[ii+10] = {};
                        for(int lllll=0;lllll<=ii+1;lllll++) ans[lllll] = -1;
                        for(int kkk=1;kkk<=ii;kkk++){
                            for(int iii=1;iii<=n;iii++){
                                if(vis[iii]==kkk){
                                    if(ans[kkk]==-1){
                                        ans[kkk] = a[kkk];
                                    }else{
                                        ans[kkk] ^= a[kkk];
                                    }
                                }
                            }
                        }
                        int cnt = 0;
                        for(int kkk=1;kkk<=ii;kkk++){
                            cnt += ans[kkk];
                        }
                        res = max(res,cnt);
                    }
                }
            }
        }
    }
    cout << res;
    return 0;
}
