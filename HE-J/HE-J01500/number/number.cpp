#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],t=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            t++;a[t]=-(s[i]-'0');
        }
    }
    sort(a+1,a+1+t);
    for(int i=1;i<=t;i++)cout<<(0-a[i]);
    cout<<endl;

    return 0;
}
