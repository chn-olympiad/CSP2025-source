//luogu uid: 1411407  yyc_Yae_Miko(blue(???) name)
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
//#define int long long
using namespace std;
int t[15],pos;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    //freeopen("number.in","r",stdin);
    //freeopen("number.out","w",stdout);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            t[s[i]-'0']++;//use the number in string
        }
    }
    bool f=1;
    for(int i=9;i>=0;i--){
        if(t[i]&&i)f=0;
        while(!f&&t[i]--){
            cout<<i;
        }
    }
    if(f)cout<<0;//yi fang wan yi
    return 0;
}
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
//I love Yae Miko !!!!!
