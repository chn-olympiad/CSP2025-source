#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cassert>
#include<algorithm>
using std::cin;
using std::cout;
#define db(x...) fprintf(stderr,x)
struct Code {
    Code() {
        freopen("number.in","r",stdin);
        freopen("number.out","w",stdout);
        std::ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
    }
    ~Code() {
        cout.flush();
        fclose(stdin);
        fclose(stdout);
    }
} code;
int c[15];
int main() {
    std::string s; cin>>s;
    int n=s.length();
    for(int i=0;i<n;i++) 
        if('0'<=s[i]&&s[i]<='9') c[s[i]-'0']++;
    for(int i=9;i>=0;i--)
        for(int j=0;j<c[i];j++)
            cout<<char(i+'0');
    cout<<'\n';
    return 0;
}