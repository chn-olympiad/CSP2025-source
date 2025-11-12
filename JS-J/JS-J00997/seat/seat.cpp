#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n+1][m+1];
    int t[n*m];
    for(int i =0;i<m*n;i++)
    {
        cin >> t[i];
    }
    int J = t[0];
    sort(t,t+n*m,[=](int a,int b){
            return  a > b;
    });
    int now = 0;
    for(int i = 1;i<=m;i++)
    {
        if(i&1){
            for(int j = 1;j<=n;j++){
                a[j][i] = t[now];
                if(t[now] == J)
                {
                    cout << i << " " << j;
                    return 0;
                }
                now++;
            }
        }
        else{
            for(int j = n;j>=1;j--){
                a[j][i] = t[now];
                if(t[now] == J)
                {
                    cout << j << " " << i;
                    return 0;
                }
                now++;
            }
        }
    }
    return 0;
}
