#include<bits/stdc++.h>
using namespace std;
char a[1000001];
bool cmp(char b,char c){
    return b>c;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int t=1;
    cin>>s;
    for(int i=0;s[i];i++){
        if(s[i]>='0' and s[i]<='9'){
            a[t++]=s[i];
        }
    }
    sort(a+1,a+1+t,cmp);
    for(int i=1;i<=t;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
