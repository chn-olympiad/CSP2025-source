#include <bits/stdc++.h>
using namespace std;
string s;
bool cmp(char a,char b){
    return b<a;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]<'0'||s[i]>'9'){
            s.erase(i,1);
            i--;
            n--;
        }
    }
    sort(s.begin(),s.end(),cmp);
    cout<<s;
    return 0;
}
