#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100000000];
long long r;
long long cnt=1;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)
        cin>>a[i];
    r=a[1];
    sort(a+1,(n*m)+a+1,cmp);
    for(long long j=1;j<=m;j++){
        if(j%2==1){
            for(long long i=1;i<=n;i++){
                if(a[cnt]==r){
                    cout<<j<<' '<<i;
                    return 0;
                    fclose(stdin);
                    fclose(stdout);
                }
                cnt++;
            }
        }else if(j%2==0){
            for(long long i=n;i>=1;i--){
                if(a[cnt]==r){
                    cout<<j<<" "<<i;
                    fclose(stdin);
                    fclose(stdout);
                    return 0;
                }
                cnt++;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
