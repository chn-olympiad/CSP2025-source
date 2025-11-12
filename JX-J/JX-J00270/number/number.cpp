#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
bool cmp(int x,int y){
    return x>y;
}//hello world!
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s;
    long long len=s.size();
    long long len2=len;
    for(int i=0;i<len;i++){
        if(s[i]>='a'&&s[i]<='z'){
            s[i]='0';
            len2--;
        }
    }
    int a[N];
    memset(a,0,sizeof(a));
    for(int i=len-1;i>=0;i--){
        a[i]=s[len-i-1]-'0';
    }
    sort(a,a+len,cmp);
    for(int i=0;i<len2;i++){
        cout<<a[i];
    }
    return 0;
}