#include<bits/stdc++.h>
using namespace std;
inline vector<char>reads(){
    vector<char>s;char c=getchar();
    while(c!='\n'&&c!=EOF){if(!(c<'0'||c>'9'))s.emplace_back(c);c=getchar();}
    return s;
}
vector<char>s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    s=reads();
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
    for(const auto&i:s)putchar(i);
    putchar('\n');
    return 0;
}