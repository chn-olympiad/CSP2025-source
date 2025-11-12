#include<bits/stdc++.h>
using namespace std;
bool cmp(char a1,char a2){
    return a1>a2;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int num=0;
    cin>>s;
    char a[s.size()];
    for(int i=0;i<s.size();i++){
        char l=s[i];
        if(l>='0'&&l<='9'){
            a[num]=l;
            num++;
        }
    }
    sort(a,a+num,cmp);
    for(int i=0;i<num;i++)
        cout<<a[i];
    return 0;
}
