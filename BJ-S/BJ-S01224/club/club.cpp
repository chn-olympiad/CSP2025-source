#include<bits/stdc++.h>
using namespace std;
int cnt[5],tmp[5][100005],n,ans,tmpp[5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        cnt[0] = cnt[1] = cnt[2] = 0;
        ans = 0;
        for(int i = 1;i <= n;i++){
            cin >> tmpp[0] >> tmpp[1] >> tmpp[2];
            if(tmpp[0] >= tmpp[1] && tmpp[0] >= tmpp[2]){
                ans += tmpp[0];
                cnt[0]++;
                tmp[0][cnt[0]] = min(tmpp[0] - tmpp[1],tmpp[0] - tmpp[2]);
            }else if(tmpp[1] >= tmpp[2]){
                ans += tmpp[1];
                cnt[1]++;
                tmp[1][cnt[1]] = min(tmpp[1] - tmpp[0],tmpp[1] - tmpp[2]);
            }else{
                ans += tmpp[2];
                cnt[2]++;
                tmp[2][cnt[2]] = min(tmpp[2] - tmpp[0],tmpp[2] - tmpp[1]);
            }
        }
        sort(tmp[0] + 1,tmp[0] + cnt[0] + 1);
        sort(tmp[1] + 1,tmp[1] + cnt[1] + 1);
        sort(tmp[2] + 1,tmp[2] + cnt[2] + 1);
        for(int i = 1;i <= cnt[0] - n / 2;i++){
            ans -= tmp[0][i];
        }
        for(int i = 1;i <= cnt[1] - n / 2;i++){
            ans -= tmp[1][i];
        }
        for(int i = 1;i <= cnt[2] - n / 2;i++){
            ans -= tmp[2][i];
        }
        cout << ans << '\n';
    }
    return 0;
}
