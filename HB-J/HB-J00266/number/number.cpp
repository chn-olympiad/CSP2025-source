#include<bits/stdc++.h>
using namespace std;
int q[100005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size(),ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]-'0'>=0&&s[i]-'0'<=9)
        {
            q[i]=s[i]-'0';
            ans++;
        }
    }
    sort(q,q+n,cmp);
    for(int i=0;i<ans;i++)
    {
        cout<<q[i];
    }
    return 0;
}
