#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],len;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]>='0' and s[i]<='9'){
            a[i]=s[i]-'0';
        }
        else{
            a[i]=-1;
        }
    }
    sort(a,a+len,cmp);
    for(int i=0;i<len;i++){
        if(a[i]==-1){
            continue;
        }
        cout<<a[i];
    }
    return 0;
}
