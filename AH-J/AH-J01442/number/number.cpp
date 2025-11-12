#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,b[1000001];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    cin>>s;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            b[i]+=s[i]-'0';
        }else{
            cnt++;
        }
    }
    sort(b,b+l,cmp);
    for(int i=0;i<l-cnt;i++){
        cout<<b[i];
    }
    return 0;
}
