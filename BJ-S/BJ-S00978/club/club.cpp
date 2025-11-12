#include<bits/stdc++.h>
int n,t;
int a[4][100001];
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t >> n;
    for(int i=1;i<=t;i++){
        int max[n+1]={0},cnt=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=3;k++){
                cin >> a[k][j];
                if(max[j]<a[k][j]){
                    max[j]=a[k][j];
                }
            }
        }
        for(int j=1;j<=n;j++){
            cnt+=max[j];
        }
        cout << cnt;
    }
}

