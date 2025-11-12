#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n;
    cin>>n;
    int a[1000][10000][10000];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int p=0;p<n;i++){
                cin>>a[i][j][p];
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
