#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    string s,a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9') s+=a[i];
    }

    sort(s.begin(),s.end(),greater<char>());
    cout<<s;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    return 0;
}
