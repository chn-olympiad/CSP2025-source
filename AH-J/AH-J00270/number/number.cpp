#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string s,p;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            p+=s[i];
        }
    }
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    cout<<p;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
