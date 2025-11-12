#include <bits/stdc++.h>
using namespace std;
const int N=1e6+110;
priority_queue<char,vector<char> > q;
char s[N];
int len;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9')q.push(s[i]);
    }
    while(!q.empty()){
        printf("%c",q.top());
        q.pop();
    }
    return 0;
}
