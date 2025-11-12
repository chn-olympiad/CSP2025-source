#include<bits/stdc++.h>
using namespace std;
int n,a;
string s;
priority_queue<int> q;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
n=s.size();
for(int i=0;i<n;i++){
    if(s[i]>='0'&&s[i]<='9')
        q.push(int(s[i]-'0'));
}
if(q.top()==0){
    cout<<0;
    return 0;
}
while(!q.empty()){
    printf("%d",q.top());
    q.pop();
}
printf("\n");
return 0;
}
