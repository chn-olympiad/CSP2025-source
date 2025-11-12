#include<iostream>
#include<string>
using namespace std;
string s,b;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    if(s.size()==1){
        cout <<s;
    }
    for(int i=0;i<=s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            b+=s[i];
        }
    }
    for(int i=0;i<=s.size();i++){
        for(int j=0;j<=s.size();j++){
            if(b[j]<b[j+1]){
                swap(b[j],b[j+1]);
            }
        }
    }
    cout <<b;
    return 0;
}
