#include<bits/stdc++.h>
using namespace std;
int a[100000];

queue<int>q;
queue<int>st;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q.push(a[i]);
    }
    int cnt=0;
    while(!q.empty()){
        int x=q.top();
        q.pop();
        if(x==k)cnt++;
        else st.push(x);
    }
    while(!st.empty()){
        int x=st.top();
        st.pop();
        q.push(x);s
    }
    return 0;
}
