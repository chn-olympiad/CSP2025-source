#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int lena=s.length();
    queue<int> q;
    for(int i=0;i<lena;i+=1){
        if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]='7' || s[i]=='8'|| s[i]=='9'){
            q.push(s[i]-'0');
        }
    }
    while(!q.empty()){
        cout<<q.front();
        q.clear();
    }
    return 0;
}
