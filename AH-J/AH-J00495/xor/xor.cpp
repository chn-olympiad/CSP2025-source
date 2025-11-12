#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[10001];
int b[10001][10001];
int c[10001][10001];
int d[10001];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        int s=a[i];
        int ans=0;
        while (s/2){
            b[i][ans]=s%2;
            s/=2;
            ans++;
        }
        if (s==1) b[i][ans]=1;
        for (int j=ans;j>0;j--) {
            c[i][j]=b[i][j];
        }
        /*for (int j=0;j<=ans;j++){
            for (int z=j+1;z<=ans;z++){
                int changes=b[i][j];
                b[i][j]=b[i][z];
                b[i][z]=changes;
            }
        }*/

    }

    //for (int i=0;i<2;i++) cout<<b[0][i];
    return 0;
}
