#include <bits/stdc++.h>

using namespace std;
bool cmp(int a,int b){
    return a > b;
}
int s[1000100],sm = 0;
string m;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> m;
    for(int i = 0;i < m.size();i++){
        if(m[i] >= '0' && m[i] <= '9'){
            s[sm] = m[i] - '0';
            sm++;
        }
    }
    sort(s,s + sm,cmp);
    for(int j = 0;j < sm;j++){
        cout<<s[j];
    }

    return 0;
}
