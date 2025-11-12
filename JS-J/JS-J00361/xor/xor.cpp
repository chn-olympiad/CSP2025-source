#include <iostream>
#include <algorithm>
using namespace std;
struct qj{
    int lp;
    int rp;
};
bool cmp(qj a,qj b){
    return a.rp==b.rp ? a.lp>b.lp : a.rp<b.rp;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int x[n][n];
    qj c[n*n];
    int len=0;
    for(int i =0;i<n;i++){
        for(int j =i;j<n;j++){
            if(i==0){
                if(j==0){
                    x[i][j]=a[0];
                }
                x[0][j]= x[0][j-1]^a[j];
            }
            x[i][j]=x[0][j]^x[0][i-1];
            if(x[i][j]==k){
                c[len].lp=i;
                c[len++].rp=j;
            }
        }
    }
    sort(c,c+len,cmp);
    int ans=0;
    int r=-1;
    for(int i =0;i<len;i++){
        if(c[i].lp >r){
            r=c[i].rp;
            ++ans;
        }
    }
    cout << ans+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
