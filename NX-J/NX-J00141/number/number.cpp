#include <bits/stdc++.h>
using namespace std;
vector<int>v;
int num[1000010];
bool cmp(int a,int b){
    if(a>b)
        return 1;
    else
        return 0;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            v.push_back(s[i]-'0');
        }
    }
    for(int i=0;i<v.size();i++){
        num[i]=v[i];
    }
    sort(num,num+v.size(),cmp);
    for(int i=0;i<v.size();i++){
        cout<<num[i];
    }
    return 0;
}
