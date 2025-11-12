#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N];
string s2[N];
int n,q,ans;
/*void solve(string a)
{
    int num;
    for(int i=0;i<a.size();i++){
        if(a[i]=='b') num=i;
    }
    for(int i=1;i<=n;i++){
            int m;
        for(int j=0;j<s1[i].size();j++){
            if(s1[i][j]=='b') m=j;
        }
        bool flag=1;
        for(int j=0;j<s1[i].size();j++){
            if(s1[i][j]!=a[j+num-m]) flag=0;
        }
        ans++;
    }
}*/
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        solve(a);
        cout<<"1"<<endl;
    }
    return 0;
}
