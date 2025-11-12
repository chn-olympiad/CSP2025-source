#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
bool cmp(char x,char y){
    if(x>y)return 1;
    else return 0;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int j=0,z=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++j]=s[i];
        }
    }
    sort(a+1,a+j+1,cmp);
    for(int i=1;i<=j;i++){
        cout<<a[i];
    }
    return 0;
}