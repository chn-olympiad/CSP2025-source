#include<bits/stdc++.h>
using namespace std;
string s[10005][2], s1, s2;
string f(string a, int b, string c, string d){
    for(int i = 0;i < c.size();i++)
        if(a[b + i] == c[i]) a[b + i] = d[i];
        else return "1";
    return a;
}
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1;i <= n;i++) cin>>s[i][0]>>s[i][1];
    while(q--){
        int cnt = 0;
        cin>>s1>>s2;
        for(int i = 1;i <= n;i++)
            for(int j = 0;j < (int)s1.size() - s[i][0].size() + 1;j++)
                if(f(s1, j, s[i][0], s[i][1]) == s2) cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}
