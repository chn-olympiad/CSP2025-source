#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0,c=0,r=0;
long long a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];
    }
    for(long long i=2;i<=n*m;i++){
        if(a[i]>a[1]){
            cnt++;
        }
    }
    c=cnt/n+1;
    r=cnt%n+1;
    if(c%2==0){
        r=n+1-r;
    }
    cout<<c<<" "<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
