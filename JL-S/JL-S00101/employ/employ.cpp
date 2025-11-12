#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ya;
string s;
int a[510];
void solvea(){
    int ans=1;
    for(int i=1; i<=n; i++){
        ans*=i;
        ans%=998*244*353;
    }
    cout<<ans;
}
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    int popp=0;
    for(int i=1; i<=n; i++){
        if(s[i]=='0'){
            ya=1;
        }
        cin>>a[i];
        if(a[i]==0){
            popp++;
        }
    }
    sort(a+1,a+1+n,cmp);
    n-=popp;
    cout<<n<<endl;
    if(ya==0)  {
        solvea();
        return 0;
    }
    return 0;
}
