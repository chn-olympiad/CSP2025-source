#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(!(s[i]>='0'&&s[i]<='9')){
            s.erase(i,1);
            i--;
        }
    }
    sort(s.begin(),s.end());
    for(int i=s.size()-1;i>=0;i--){
        cout<<s[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
