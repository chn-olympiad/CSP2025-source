#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
string s;
int l=1,a[1000001],num;
signed main(){
    freopen("text.in","r",stdin);
    freopen("text.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[l]=s[i]-'0';
            l++;
        }
    }
    sort(a+1,a+l,cmp);
    for(int i=1;i<l;i++) cout<<a[i];
    return 0;
}
