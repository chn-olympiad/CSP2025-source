#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(long long i=0;i<s.size();i++){
        if(s[i]<'0' || s[i]>'9'){
            s.erase(i,1);
            i--;
        }
    }
    sort(s.begin(),s.end(),cmp);
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
