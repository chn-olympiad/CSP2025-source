#include <bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int a[N],cnt=0;
bool cmp(int a,int b){
    return a>b;
    }
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt++;
            a[cnt]=int(s[i])-48;
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++) cout<<a[i];
    return 0;
}
