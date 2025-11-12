#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
signed main(){
    cin.tie(0);
    cout.tie(0);
    freopen(stdin,"r","number.in");
    freopen(stdout,"w","number.out");
    string s;
    cin >> s;
    vector<int> v;
    fr(i,0,s.size())
        if(s[i]>='0' and s[i]<='9')
            v.push_back(s[i]-'0');
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    fr(i,0,v.size())cout << v[i];
    return 0;
}
/*
& &
(~)
written by Leon2012
I love CCF!
I'm going to AK CSP-J/S!
*/
