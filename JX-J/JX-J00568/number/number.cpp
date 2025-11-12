#include<bits/stdc++.h>
using namespace std;
string s;
char b;
int a[1000010],j;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'>=0&&s[i]-'0'<=9){
            a[j]=s[i]-'0';
            j++;
       }
    }
    sort(a,a+j,cmp);
    for(int i=0;i<j;i++){
        cout<<a[i];
    }
    return 0;
}
