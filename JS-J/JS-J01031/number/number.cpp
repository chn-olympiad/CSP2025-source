#include<bits/stdc++.h>
using namespace std;

int a[10];
int main(){
    ifstream fin("number.in",ios::in);
    ofstream fout("number.out",ios::out);

    string s,num = "";
    fin>>s;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])) a[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        if(a[i]>0){
            for(int j=0;j<a[i];j++){
                num = num+char(i+'0');
            }
        }
    }

    if(num[0]=='0') fout<<"0";
    else fout<<num;
    return 0;
}
