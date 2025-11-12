#include<bits/stdc++.h>
using namespace std;
int n,t,num[5];
int a1[100010],a2[100010],a3[100010];
int cnt1,cnt2,cnt3,ans1,ans2,ans3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a1[i] >> a2[i] >> a3[i];
        }
        int hf = n/2;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n;j++){
                if(a1[i] != 0 && a1[i] >= a1[j] && ans1 < hf){
                    cnt1 += a1[i];
                    ans1++;
                    a1[i] = 0;
                    a2[i] = 0;
                    a3[i] = 0;
                }
            }
            for(int j=1; j<=n; j++){
                if(a2[i] != 0 && a2[i] >= a2[j] && ans2 < hf){
                    cnt2 +=  a2[i];
                    ans2++;
                    a1[i] = 0;
                    a2[i] = 0;
                    a3[i] = 0;
                }
            }
            for(int j=i; j<=n; j++){
                if(a3[i] != 0 && ans3 < hf){
                    cnt3 += a3[i];
                    ans3++;
                    a1[i] = 0;
                    a2[i] = 0;
                    a3[i] = 0;
                }
            }
        }
        cout <<  cnt1 + cnt2 + cnt3+3;
    }
    return 0;
}
