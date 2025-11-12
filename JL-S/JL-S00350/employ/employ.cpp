#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,c[550],t=0;
    string s;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    cin>>c[i];
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1'&&i<=c[i+1])
            t++;
    }
    if(t>=m)
    cout<<"1";
    return 0;
}
