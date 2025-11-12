#include <bits/stdc++.h>
using namespace std;

int n,ans,a[5005],b[5005];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >> n;
    for (int i = 1;i <= n;++i) cin >> a[i];
    sort(a+1,a+1+n);
    for (int len = 3;len <= n;++len){
        for (int l = 1,r = len;r <= n;++l,++r){
           // printf("区间：%d~%d, 最大值：%d\n",l,r,a[r]);
			do{
                int sum = 0;
                for (int lg = 2;lg < len;++lg){
                    for (int i = 1;i <= lg;++i){
                        //printf("%d ",a[i]);
                        sum += a[i];
                    }
                }
                if (sum > a[r]*2) ans++;
                cout << endl;
            }while (next_permutation(a+l,a+r));
        }
    }
    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

