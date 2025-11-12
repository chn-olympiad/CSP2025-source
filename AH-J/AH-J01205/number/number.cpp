#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int a[maxn];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int tmp=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[tmp]=s[i]-'0';tmp++;
        }
    }
    sort(a,a+tmp);
    for(int i=tmp-1;i>=0;i--){
        printf("%d",a[i]);
    }
}
