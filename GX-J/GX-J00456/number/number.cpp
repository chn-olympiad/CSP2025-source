#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("number1.in","r",stdin);
    //freopen("number1.out","w",stdout);
    string s;
    cin >> s;
    vector<int> a;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            a.push_back(0);
        }
        else if(s[i]=='1'){
            a.push_back(1);
        }
        else if(s[i]=='2'){
            a.push_back(2);
        }
        else if(s[i]=='3'){
            a.push_back(3);
        }
        else if(s[i]=='4'){
            a.push_back(4);
        }
        else if(s[i]=='5'){
            a.push_back(5);
        }
        else if(s[i]=='6'){
            a.push_back(6);
        }
        else if(s[i]=='7'){
            a.push_back(7);
        }
        else if(s[i]=='8'){
            a.push_back(8);
        }
        else if(s[i]=='9'){
            a.push_back(9);
        }
        else{
            a.push_back(' ');
        }
        cout << a[i];
    }
    return 0;
}
