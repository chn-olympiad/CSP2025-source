//Password:#Shang4Shan3Ruo6Shui4(dai4 # hao4!!!!!)
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,t;
    getline(cin,s);
    for(char c:s){
        if(isdigit(c)){
            t.push_back(c);
        }
    }sort(t.begin(),t.end(),greater<char>());
    cout<<t;
    fclose(stdin);
    fclose(stdout);
}
