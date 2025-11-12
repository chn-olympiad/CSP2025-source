#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],sum=0;
queue<int> q;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a'&&s[i]<='z') continue;
        q.push(s[i]-'0');
    }
    while(!q.empty()){
        int t=q.front();
        a[sum]=t;
        q.pop();
        sum++;
    }
    sort(a,a+sum);
    for(int i=sum-1;i>=0;i--) cout<<a[i];
    return 0;
}
