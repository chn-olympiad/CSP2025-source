#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    sort(s.begin(),s.end());
    for(int i=s.size()-1;i>=0;i--) if(s[i]>='0'&&s[i]<='9') cout<<s[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
