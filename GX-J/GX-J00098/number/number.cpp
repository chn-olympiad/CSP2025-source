#include<bits/stdc++.h>
using namespace std;
string s;
int l=0,a[1000005];
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            l++;
            a[l]=s[i]-'0';
        }
    }
    sort(a+1,a+l+1,cmp);
    for(int i=1;i<=l;i++) cout<<a[i];
    return 0;
}
