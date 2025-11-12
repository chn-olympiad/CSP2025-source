#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    string s;
    cin>>s;
    const int N=1e6+10;
    int a[N],al=0,sl=s.size();
    for(int i=0;i<sl;i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[al]=s[i]-'0';
            al++;
        }
    }
    sort(a,a+al,greater<int>());
    for(int i=0;i<al;i++){
        cout<<a[i];
    }
    return 0;
}
