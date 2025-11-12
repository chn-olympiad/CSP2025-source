#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,p=0,c[10001],x=0,mi=0;
string num;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>num;
    for(i=1;i<=n;i++) cin>>c[i];
    for(j=1;j<=n;j++){
        mi=0;
        x=0;
        for(i=1;i<=n;i++){
            if(num[i] == '1'){
                x++;
                continue;
            }
            else if(x >= c[i]){
                x++;
                continue;
            }
            else mi++;
            if(mi == m)
                p++;
        }
    }
    cout<<p%998244353;
    cout<<endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
