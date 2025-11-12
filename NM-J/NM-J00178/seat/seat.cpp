#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n * m + 1);
    int a1;
    cin>>a1;
    a[1] = a1;
    for(int i = 2;i <= n * m ;i++){
        cin>>a[i];

    }
    int v;
    sort(a.begin()+1,a.end(),greater<int>());
    vector<vector<int> > seat(n+1,vector<int>(m+1,0));
    int z = 1;
    for(int i = 1;i<=m;i++){
        if(i % 2 == 1){
            for(int j = 1;j<=n;j++){
                seat[j][i] = a[z];
                z++;
            }
        }else{
            for(int j = n;j>=1;j--){
                seat[j][i] = a[z];
                z++;

            }
        }

    }
    int x,y;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(seat[i][j] == a1){
                x = i;
                y = j;
            }

        }
    }
    cout<<y<<" "<<x;
    return 0;
}
