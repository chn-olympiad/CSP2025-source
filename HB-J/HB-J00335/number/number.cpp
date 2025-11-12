#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+200;
string s;
int top;
char a[N];

bool cmp(int x, int y){
    return x >= y;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i]>='a'&&s[i]<='z')    continue;
        else  a[++top] = s[i];
    }

    sort(a+1, a+top+1, cmp);
    for(int i = 1; i <= top; i++){
        cout << a[i];
    }

    return 0;
}
