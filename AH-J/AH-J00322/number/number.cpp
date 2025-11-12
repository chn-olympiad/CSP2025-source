//freopen
#include<bits/stdc++.h>
using namespace std;
string s,t;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')t+=s[i];
    }
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
    cout<<t;
    return 0;
}
//#Shang4Shan3Ruo6Shui4
//I wonder, why things have happened. Could you imagine, the world is boring?
