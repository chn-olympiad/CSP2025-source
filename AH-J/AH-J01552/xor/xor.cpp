#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
long long f[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        f[i]=(f[i-1]^x);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((f[j]^f[i-1])==m)
                    cnt++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
