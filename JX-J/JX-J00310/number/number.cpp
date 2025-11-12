#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string s;
int len;
char vet[1000005];
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    int s_len=s.length();
    for (int i=0;i<s_len;i++){
        if (s[i]>='0' && s[i]<='9') {
            vet[len]=s[i];
            len++;
        }
    }
    sort(vet,vet+len,cmp);
    if (vet[0]!='0') for (int i=0;i<len;i++) printf("%c",vet[i]);
    else printf("%d",0);
    return 0;
}
