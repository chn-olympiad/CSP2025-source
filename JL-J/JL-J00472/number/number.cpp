#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long ans = 0;
    int head = 0;
    int b;
    int x = 0;
    for(int i = 0;i<s.length();i++){
        head = 0;
        x = 0;
        for(int j = 0;j<s.length();j++){
                int k;
                k = s[j]-48;
                if(k<=9&&head<=k){
                    head = k;
                    b = j;
                    x =1;
                }
        }
        s[b] = 'a';
        if(x == 1){
            ans = ans*10+head;
        }
    }
    cout<<ans;
}
