#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int m,n,a[maxn];
string s;
int sum=0,ans=0,;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i]==1 && a[j]<ans) sum++;
        }
        ans++;
    }
    cout<<sum;
    return 0;
}

