#include <bits/stdc++.h>
using namespace std;
int main(){
    char a='0';
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s="";
    cin>>s;
    for(int i=0;i<999999;i++){
        if(s[i]=='1'|| s[i]=='2'|| s[i]=='3'|| s[i]=='4'|| s[i]=='5'|| s[i]=='6'|| s[i]=='7'|| s[i]=='8'||s[i]=='9'){
            if(s[i]>a){
                a=s[i];
            }
        }
        cout<<a;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
