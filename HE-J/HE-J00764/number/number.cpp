#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000005],tot;
bool cmp(int x,int y){
    return x>y;
}int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[i]=s[i]-'0';
            tot++;
        }
    }sort(num,num+len,cmp);
    for(int i=0;i<tot;i++)cout<<num[i];
    return 0;
}
