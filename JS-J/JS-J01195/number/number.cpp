#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
bool cmp(const int &x,const int &y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    //ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9')
            v.push_back(s[i]-'0');
    sort(v.begin(),v.end(),cmp);
    for(auto x:v) printf("%d",x);
    return 0;
}
/*
YangJunShuoZaiYouBianEi  QwQ
*/
