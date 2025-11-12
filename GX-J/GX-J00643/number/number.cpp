#include<bits/stdc++.h>
using namespace std;
string s;
int cnt=0;
int a[1000003];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            a[cnt]=s[i]-'0';
            cnt++;
        }
    }
    sort(a,a+cnt,cmp);
    for(int i=0;i<cnt;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
