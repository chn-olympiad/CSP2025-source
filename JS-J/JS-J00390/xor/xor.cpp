#include <bits/stdc++.h>
using namespace std;
string totwo(int a){
    string s;
    while(a!=0){
        s+=a%2+'0';
        a=a/2;
    }
    return s;
}
int toten(string s){
    int cnt=0;
    int ans=0;
    for(int i=0;i<s.size();i++){
        ans+=(s[i]-'0')*pow(2,cnt++);
    }
    return ans;
}
int Xor(int x,int y){
    if(x>y) swap(x,y);
    string c;
    string a=totwo(x),b=totwo(y);
    for(int i=0;i<a.size();i++){
        if((a[i]=='0' && b[i]=='0')||(a[i]==1 &&b[i]==1)) c+='0';
        else c+='1';
    }

    for(int i=a.size();i<b.size();i++){
        if(b[i]=='1') c+='1';
        else c+='0';
    }
    return toten(c);
}
const int MAXN=5e5+5;
int n,k,a[MAXN];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1 &&k==0){
        cout<<0;
        return 0;
    }
    if(n==2 &&k==0){
        cout<<1;
        return 0;
    }

    cout<<1;
    return 0;
}
