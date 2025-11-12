#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    priority_queue<char> q;
    char c;
    while(c=getchar()){
        if(c>='0'&&c<='9')q.push(c);
        if(c=='\n')break;
    }
    if(q.top()=='0')cout<<'0';
    else{
        while(!q.empty()){
            cout<<q.top();
            q.pop();
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
