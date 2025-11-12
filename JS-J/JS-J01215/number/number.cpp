#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+9;
string s;
int a[maxn];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            if(s[i]=='0') cnt++;
            a[i]=s[i]-'0';
        }
    }
    sort(a,a+s.size(),cmp);
    for(int i=0;i<s.size();i++){
        if(a[i]!=0) cout<<a[i];
    }
    for(int i=1;i<=cnt;i++){
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
