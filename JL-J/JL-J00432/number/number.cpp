#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen ("number.in","r",stdin);
    freopen ("number.out","w",stdout);
    string s;
    int h=1;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&& s[i]<='9'){
            a[h]=s[i]-'0';
            h++;
        }
    }
    sort(a+1,a+h);
    for(int i=h-1;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
