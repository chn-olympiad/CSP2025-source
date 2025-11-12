#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    char c[105];
    for(int i=1;i<=s.size();i++){
        c[i]=s[i];
    }
    int b=100;
    double a;
    for(int i=1;i<=s.size();i++){

            for(int j=1;j<=s.size();j++){
                if(c[i]-'0'<10&&c[i]-'0'<=b){
                b=c[i]-'0';
            }
            }

            a+=b;
            a/=10;

            }


    a*=s.size()*10;
    cout<<a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
