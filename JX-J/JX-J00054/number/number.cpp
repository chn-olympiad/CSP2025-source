#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int id=0;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[++id]=s[i]-48;
        }
    }
    sort(a+1,a+id+1,greater<int>());
    for(int i=1;i<=id;i++){
        cout<<a[i];
    }
    return 0;
}
