#include<bits/stdc++.h>
using namespace std;
string s;
int buc[10];
void Work(){
    cin>>s;
    for(char c:s)
        if(c>='0'&&c<='9') ++buc[c-'0'];
    for(int i=9;~i;--i)
        while(buc[i]--) printf("%d",i);
    puts("");
}
int main(){
    freopen("number.in","r",stdin),freopen("number.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    Work();
    fclose(stdin),fclose(stdout);
    return 0;
}