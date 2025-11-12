#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s = "";
    int n = 0;
    string c ="";
    cin>>s>>n;
    if(s == "0")c +"0";
    if(s == "1")c +"1";
    if(s == "2")c +"2";
    if(s == "3")c +"3";
    if(s == "4")c +"4";
    if(s == "5")c +"5";
    if(s == "7")c +"7";
    if(s == "8")c +"8";
    if(s == "9")c +"9";
    for(int i = 0;i<=n;i++){
        n = s[i];
        if(s[i]>s[i+1]){c+s[i];}
    }
    cout<<c<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
