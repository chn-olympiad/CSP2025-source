#include <bits/stdc++.h>
using namespace std;
string s="",a="";
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;

    for(int i=1;i<=s.size();i++){
        a="";
        if (s[i]>='0'&&s[i]<='9'){
            if(s[i]>s[i+1]){
                a=s[i];
            }else{
                a=s[i+1];

            }

        }
        cout<<a;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
