#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,v[100001],t,cnt=1;
bool cmp(ll a,ll b){return a>b;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>v[i];
    t=v[1];
    sort(v+1,v+n*m+1,cmp);
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                if(v[cnt]==t){
                    cout<<i<< ' '<<j;
                    return 0;
                }
                cnt++;
            }
        }else{
            for(int j=m;j>=1;j--){
                if(v[cnt]==t){
                    cout<<i<<' '<<j;
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
