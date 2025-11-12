#include<bits/stdc++.h>
using namespace std;
//wu ri n xing wu shen:
//define int long long & signed main hu?
//freopen shan zhu shi hu?
//da yang li ce shi le hu?
//bian liang chu shi hua le hu?
//han shu xie fan hui zhi le hu?
//shu zu da xiao he shi hu?
//bu yong zi mu+shu zi / wan zheng dan ci zuo bian liang ming hu?
//bian yi tong guo le hu?
//jian cha shu chu shi kong ge hai shi huan hang le hu?
#define int long long
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0;i<s.size();i++)if(s[i]>='0' && s[i]<='9')v.push_back(s[i]-'0');
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i:v)cout<<i;
    return 0;
}
