#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    vector<int> ve;
    for(int i=0;i<n;i++){
        if(s[i]<='9' && s[i]>='0'){
            ve.push_back(s[i]-'0');
        }
    }
    n=ve.size();
    int a[10];
    for(int i=0;i<10;i++) a[i]=0;
    for(int i=0;i<n;i++){
        a[ve[i]]++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
