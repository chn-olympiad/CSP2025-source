#include<bits/stdc++.h>
using namespace std;
int n,m;
int nx[505];
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;++i){
        cin>>nx[i];
    }
    sort(nx+1,nx+n+1);
    int sum=1;
    if(m==1){
        int sl=1;
        for(int i=2;i<=n;++i){
            if(nx[i]==nx[i-1]){
                    sl++;
            }else{
                sum=sum*sl*(sl-1);
            }

        }
        cout<<sum;
    }
    int sl=1;
        for(int i=2;i<=n;++i){
            if(nx[i]==nx[i-1]){
                    sl++;
            }else{
                sum=sum*sl*(sl-1);
            }

        }
    cout<<sum;
    return 0;
}
