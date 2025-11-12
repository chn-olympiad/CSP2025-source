#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],l;
bool f(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[l]=s[i]-'0';
            l++;
        }
    }
    sort(a+0,a+l,f);
    if(a[0]==0) cout<<0;
    else for(int i=0;i<l;i++) cout<<a[i];
    return 0;
}
