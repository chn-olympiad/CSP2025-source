#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s1,s2;
    cin>>s1;
    for(int i=0;i<s1.size();i++){
        if(isdigit(s1[i])) s2+=s1[i];
    }
    sort(s2.begin(),s2.end());
    reverse(s2.begin(),s2.end());
    cout<<s2<<endl;
    return 0;
}