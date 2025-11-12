#include<bits/stdc++.h>
using namespace std;
char s[1000001];
bool cmp(char a,char b){
    if(a<b) return false;
    return true;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(char w='9';w>='0';w--) for(char key:s) if(key==w) cout<<w;
    cout<<endl;
    return 0;
}
