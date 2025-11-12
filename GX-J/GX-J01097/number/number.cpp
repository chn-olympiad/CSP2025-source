#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    v.clear();
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9')
            v.push_back((int)(s[i]-'0'));
    }
    sort(v.begin(),v.end());
    n=v.size();
    for(int i=n-1;i>=0;i--)
        printf("%d",v[i]);
    puts("");
    return 0;
}
