#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
string s;
priority_queue<int> q;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
        if('0'<=s[i]&&s[i]<='9'){
            int a=s[i]-'0';
            q.push(a);
        }
    while(!q.empty()){
        int t=q.top();
        printf("%d",t);
        q.pop();
    }
    return 0;
}
