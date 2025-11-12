#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            a[l]=s[i]-'0';
            l++;
        }
    }
    sort(a,a+l,greater<int>());
    for(int i=0;i<l;i++){
        cout<<a[i];
    }
    return 0;
}
