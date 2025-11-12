#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int num[N],len;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[++len]=s[i]-'0';
        }
    }
    sort(num+1,num+len+1,cmp);
    for(int i=1;i<=len;i++){
        cout<<num[i];
    }
    return 0;
}
