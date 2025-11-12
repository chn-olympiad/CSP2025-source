#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int >
#define ll long long
#define IO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll N=1e5+10;
int a[N][5];
int n,n2;
bool flag=0;
ll abc(ll s){
    flag=0;
    string c;
    ll ba=0,x[4]={};
    s++;
    while(s>0){
        if(s%10>3){
            s=1;
            s+=10;
        }
        c+=s%10+'0';
        if(x[s%10]>n2){
            flag=1;
            return -1;
        }
        x[s%10]++;
        s/=10;
    }
    for(int i=c.size()-1;i>=0;i--){
        ba+=c[i]-'0';
        ba*=10;
    }
    ba/=10;
    //cout<<ba<<' ';
    return ba;
}
void solve(){
    ll ans=0,y;
    cin>>n;
    n2=n/2;
    for(int i=0;i<n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    int s=0;
    for(int i=0;i<n;i++){
        s++;
        s*=10;
    }
    s++;
    y=to_string(s).size();
    while(1){
        int q,rs[5]={};
        s=abc(s);
        q=to_string(s).size();
        //cout<<y<<' '<<q<<endl;
        if(flag==1)continue;
        if(q>y){
            //cout<<ans<<endl;
            return ;
        }
        ll sum=0;
        for(int i=n-1;i>=0;i--){
            if(rs[s%10]>=n2){
                break;
            }else {
                rs[s%10]++;
                sum+=a[i][s%10];
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return ;
}
int main (){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while (T--){
        solve();
    }
    return 0;
}
