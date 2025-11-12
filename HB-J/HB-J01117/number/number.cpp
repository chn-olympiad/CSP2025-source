#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N];
bool cmp(int x,int y){
return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int top=0,n=0;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&& s[i]<='9'){
            top++,n++;
            a[top]=s[i]-'0';
        }
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }
    return 0;
}
