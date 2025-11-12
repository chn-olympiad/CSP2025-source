#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
vector<int> vec;
bool cmp(int x,int y){return x>y;}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            vec.push_back(s[i]-'0');
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    int flag=0;
    for(auto v:vec){
        if(v!=0)flag=1;
        if(flag)printf("%d",v);
    }
    printf("\n");
    return 0;
}
