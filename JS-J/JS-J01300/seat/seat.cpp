#include <bits/stdc++.h>

using namespace std;
int n,m;
int nm[100+9];
int cnt;
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>nm[i];
        if(nm[i]>nm[1]){
            cnt++;
        }
    }
    cnt++;
    if(cnt%n==0){
        if(cnt/n%2==1){
            cout<<cnt/n<<' '<<n-cnt%n;
        }
        else{
            cout<<cnt/n<<' '<<cnt%n+1;
        }
    }
    else{
        if((cnt/n+1)%2==1){
            cout<<cnt/n+1<<' '<<cnt%n;
        }
        else{
            cout<<cnt/n+1<<' '<<n-cnt%2+1;
        }
    }
    return 0;
}
