#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i;
    string s,c;
    int a;
    vector<int> n;
    cin>>s;
    for(i=0;i<s.length();i++){
        c="";
        a=s[i];
        if(48<=a and 57>=a){
            n.push_back(a-48);
        }
    }
    sort(n.begin(),n.end());
    for(i=n.size()-1;i>=0;i--){
        cout<<n[i];
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
