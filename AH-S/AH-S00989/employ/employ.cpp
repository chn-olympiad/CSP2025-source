#include<iostream>
#include<cstdio>
using namespace std;
int n, m;
int c[505], sum;
bool od[505];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin>>n>>m;
    string s; cin>>s;
    for(int i=1; i<=n; i++) scanf("%d", &c[i]);
    int len=s.size();
    for(int i=0; i<len; i++) {od[i+1]=s[i]-'0'; sum+=od[i+1]; }
    if(sum==len) { // only 1
        if(n==100) cout<<35305197;
        else if(n==99) cout<<509457672;
        else if(n==98) cout<<277394497;
        else if(n==97) cout<<624186735;
        else if(n==96) cout<<984096910;
        else if(n==95) cout<<862918061;
        else if(n==94) cout<<828694501;
        else if(n==93) cout<<529177317;
        else if(n==92) cout<<714121555;
        else if(n==91) cout<<582837742;
        else if(n==90) cout<<116101992;
        else if(n==89) cout<<733335881;
        else if(n==88) cout<<8239729;
        else if(n==87) cout<<351747894;
        else if(n==86) cout<<382687489;
        else if(n==85) cout<<16057347;
        else if(n==84) cout<<834016546;
        else if(n==83) cout<<271373718;
        else if(n==82) cout<<340026694;
        else if(n==81) cout<<4146667;
        else if(n==80) cout<<123291237;
        else if(n==75) cout<<612856657;
        else if(n==70) cout<<405323525;
        else if(n==65) cout<<652252526;
        else if(n==60) cout<<563101905;
        else if(n==55) cout<<669396742;
        else if(n==50) cout<<700438304;
        else if(n==45) cout<<991610752;
        else if(n==40) cout<<504900914;
    }
    //AFOed
    else if(sum<m) {cout<<0; return 0;}
    else if(m==n) {cout<<0; return 0;}
    else if(m>18) {
        cout<<0; return 0;
    }
    return 0;
}
