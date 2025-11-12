#include<bits/stdc++.h>
using namespace std;
unsigned long long ull;
typedef long long ll;
int MOD=998244353;
int nm[600][600];
void init(){
    nm[0][0]=1;
    for(int i=1;i<=500;i++){
        for(int j=0;j<=i;j++){
            if(j!=0){
                nm[i][j]=nm[i-1][j]+nm[i-1][j-1];
            }else{
                nm[i][j]=nm[i-1][j];
            }nm[i][j]%=MOD;
        }
    }
}
int n,m;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    init();
    cin>>n>>m;
    cout<<nm[n][m];
    return 0;
}
