#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long sum;
int t,a[N][5],b[5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            int mx=0;
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            mx=max(a[i][1],max(a[i][3],a[i][2]));
            if(b[1]==n/2){
                mx=max(a[i][2],a[i][3]);
                if(mx==a[i][2]) b[2]++;
                else b[3]++;
            }else if(b[2]==n/2){
                mx=max(a[i][1],a[i][3]);
                if(mx==a[i][1]) b[1]++;
                else b[3]++;
            }else if(b[3]==n/2){
                mx=max(a[i][2],a[i][1]);
                if(mx==a[i][2]) b[2]++;
                else b[1]++;
                sum+=mx;
            }else{
                mx=max(a[i][1],max(a[i][3],a[i][2]));
                if(mx==a[i][1]) b[1]++;
                else if(mx==a[i][2]) b[2]++;
                else b[3]++;
            }
            sum+=mx;
        }
        cout<<sum;
        sum=0;
    }
    return 0;
}

