#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],p[505],ans;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)p[i]=i;
    do{
        int sum=0,k=0;
        for(int i=1;i<=n;i++){

            if(s[i]=='1'&&k<c[p[i]]){
                sum++;
            }else{
                k++;
            }

            //cout<<s[i]<<" "<<p[i]<<" "<<sum<<" "<<k<<endl;
        }
        ans+=(sum>=m);
        ans%=998244353;
        //cout<<endl;
    }while(next_permutation(p+1,p+n+1));
    cout<<ans<<endl;
    return 0;
}
