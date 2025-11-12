#include<bits/stdc++.h>
using namespace std;
const int mx=1E6+5;
int a[mx];
int cnt=0;
string s;
int main(){
   freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    //cout<<len<<endl;
    for(int i=0;i<len;i++){
        char ch=s[i];
        if(ch>='0'&&ch<='9') a[++cnt]=(ch-'0');
    }
    sort(a+1,a+1+cnt);
    for(int i=cnt;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
