#include<bits/stdc++.h>
using namespace std;
vector<int>vec;
string str;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    getline(cin,str);
    for(auto k:str)
    {
        if(k>='0'&&k<='9') vec.push_back(k-'0');
    }
    sort(vec.begin(),vec.end(),greater<int>());
    string g="";
    for(auto k:vec) g+=(k+'0');
    cout<<g<<endl;
    return 0;
}
