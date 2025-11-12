#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n,a[500],y,e=501;
    string s;
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==n){
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                cout<<0;
                return 0;
            }
        }
        for(int i=1;i<=s.size();i++){
            y+=i*(s.size()-i);
        }
        cout<<y;
        return 0;
    }
    return 0;
}
