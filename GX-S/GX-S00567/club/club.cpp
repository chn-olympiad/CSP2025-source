#include <bits/stdc++.h>
using namespace std;

map<int,map<int,int>>a;
map<int,int>flag;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mx=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=3;j++){
                cin >> a[i][j];
                mx=max(mx,a[i][j]);
            }
        }
        int cnt=n,sum=0;
        while(cnt!=0){
            for (int i=1;i<=n;i++){
                for (int j=1;j<=3;j++){
                    if (a[i][j]==mx){
                        a[i][j]=0;
                        if (flag[j]!=n/2){
                            flag[j]++;
                            sum+=mx;
                            cnt--;
                        }
                    }
                }
            }
            mx--;
        }
        cout << sum << endl;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=3;j++){
                a[i][j]=0;
            }
        }
        for (int i=1;i<=5;i++){
            flag[i]=0;
        }
    }


    return 0;

}
