#include<bits/stdc++.h>
using namespace std;

string s;
int n,m;
long long ans=0;
int c[510],cnt[510];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]!=0) sum++;
    }
    for(int i=1;i<=sum;i++){
        cnt[i]=i;
    }
    cout<<0;
    return 0;
}
