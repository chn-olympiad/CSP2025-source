#include<bits/stdc++.h>
using namespace std;
int m[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int se=s.size();
    for(int i=0;i<se;i++)
        if(s[i]<='9'&&s[i]>='0')m[s[i]-'0']++;
    bool f=0;
    for(int i=9;i>=1;i--)while(m[i]--){
        cout<<i;
        f=1;
    }
    if(f){
        while(m[0]--){
            cout<<0;
        }
    }
    else cout<<0;
    return 0;
}
