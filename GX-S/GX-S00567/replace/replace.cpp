#include <bits/stdc++.h>
using namespace std;

map<string,string>a;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for (int i=1;i<=n;i++){
        string s1,s2;
        cin >> s1 >> s2;
        a[s1]=s2;
    }
    for (int i=1;i<=q;i++){
        string s3,s4;
        cin >> s3 >> s4;
        string s="";
        for (int i=0;i<s3.length();i++){
            if (s3[i]!=s4[i]){
                s+=s3[i];
            }
        }
        if(a[s]!=""){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }

    }


    return 0;
}
