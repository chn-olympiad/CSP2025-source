#include<bits/stdc++.h>

using namespace std;
const int N=1e6+5;
string s;
char number[N];
int n=0;
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9')number[n++]=s[i];
    }
    sort(number,number+n,cmp);
    for(int i=0;i<n;i++){
        cout<<number[i];
    }
    return 0;
}
