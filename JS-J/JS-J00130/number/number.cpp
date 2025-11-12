#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[1000005];
    cin.tie(0);
    cin>>s;
    int tot=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++tot]=s[i]-'0';
        }
    }
    sort(a+1,a+tot+1,cmp);
    for(int i=1;i<=tot;i++){
        cout<<a[i];
    }
    return 0;
}
