#include<bits/stdc++.h>
using namespace std;
int l,a[1000005];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int r = s.length();
    for(int i = 0;i<r;i++){
        if(s[i]>='0' && s[i] <= '9'){
            a[++l] = (s[i] - '0');
        }
    }
    sort(a+1,a+l+1);
    while(a[l] == 0 &&l > 1) l--;
    for(int i = l;i>=1;i--){
        cout<<a[i];
    }
}
