#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool pd(int a,int b){
    if(a>b) return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int b=s.size(),c=0;
    int a[b],cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>=49 && s[i]<=57 || s[i]-'0'==0){
            c=s[i]-'0';
            a[cnt]=c;
            cnt=cnt+1;
        }
    }
    sort(a+0,a+0+cnt+1);
    for(int i=cnt;i>0;i--){
        cout<<a[i];
    }
    return 0;
}
