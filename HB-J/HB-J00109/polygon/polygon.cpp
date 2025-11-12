#include<bits/stdc++.h>

using namespace std;

const int N=5*1e5+5,M=3005;
int a[N];
int mp[M][M];

int main(){

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m,cnt=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int ans=a[i];
            for(int k=i+1;k<=j;k++){
                ans=ans^a[k];
            }
            if(ans==m) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
