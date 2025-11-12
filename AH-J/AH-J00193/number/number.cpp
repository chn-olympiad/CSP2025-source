#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    sort(s.begin(),s.end());
    int len=s.size();
    for(int i=len-1;i>=0;i--){
        if( s[i]>='0' && s[i]<='9' ){
            cout<<s[i];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
