#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s = "";
    cin >> s;
    vector <int> v;
    for(int i=0; i<s.size(); i++){
        if(s[i] >= '0' and s[i] <= '9'){
            v.push_back(s[i]-'0');
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
