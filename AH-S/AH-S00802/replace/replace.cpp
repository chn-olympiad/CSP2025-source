#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const unsigned long long INF=18446744073709551615;
int n,q;
string s[N][2];
bool check(string a,string a1,string b,string b1){
    if(a.find(a1)==INF||b.find(b1)==INF)return false;
    int f=a.find(a1);
    string x,z;
    for(int i=0;i<f;i++)if(a[i]!=b[i])return false;
    for(int i=f+a1.size();i<a.size();i++)if(a[i]!=b[i])return false;
    return true;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=1;i<=q;i++){
        string x,y;
        cin>>x>>y;
        if(x.size()!=y.size()){
            printf("0\n");
            continue;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(check(x,s[i][0],y,s[i][1]))cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
