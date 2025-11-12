#include<bits/stdc++.h>
using namespace std;
ifstream fin("number.in");
ofstream fout("number.out");
int a[1145014];
int main(){
    string s;
    fin>>s;
    int top=0;
    int siz=s.size();
    for(int i=0;i<siz;i++){
        if('0'<=s[i] and s[i]<='9'){
            a[top++]=s[i]-'0';
        }
    }
    sort(a,a+top);
    for(int i=top-1;i>=0;i--){
        fout<<a[i];
    }
}
