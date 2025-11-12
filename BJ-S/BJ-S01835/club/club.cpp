#include<bits/stdc++.h>
using namespace std;
int a[100001][10];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,t;
    cin>>t>>n;
    while(t){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 3;j++){
            cin>>a[i][j];
        }
    }
    int sam = 0;
    for(int i = 1;i <= n;i++){
        int maxx = -1;
        for(int j = 1;j <= 3;j++){
            maxx = max(maxx,a[i][j]);
        }
        sam += maxx;
    }

    cout<<sam<<endl;
    t--;
    }
    return 0;
}
