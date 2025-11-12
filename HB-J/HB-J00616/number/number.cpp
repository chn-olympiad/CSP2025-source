#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.size(),cnt=0;
    for(int i=0;i<l;i++){
        if(s[i]>='0' && s[i]<='9'){
            a[++cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=cnt;i++){
        printf("%d",a[i]);
    }
    return 0;
}
