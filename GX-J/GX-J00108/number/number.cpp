#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    if(x>y)return true;
    return false;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    int a[s.size()+1],sum=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[sum]=s[i]-'0';
            sum++;
        }
    }
    sort(a,a+sum,cmp);
    for(int i=0;i<sum;i++)cout<<a[i];
    return 0;
}
