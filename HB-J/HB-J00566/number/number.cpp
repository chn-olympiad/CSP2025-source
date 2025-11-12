#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
char a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(a!='\n'){
        scanf("%c",&a);
        if(a>='0'&&a<='9'){
            q.push((a-'0'));
        }
    }
    while(!q.empty()){
        printf("%d",q.top());
        q.pop();
    }
    return 0;
}

