#include <bits/stdc++.h>
#include <string>
#include <queue>
using namespace std;
string s;
priority_queue <int> q;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i = 0;i < s.size();i++)
        if ('0'<= s[i] && s[i]<= '9')
            q.push(int (s[i]-'0'));
    while (!q.empty()){
        cout<<q.top();
        q.pop();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
