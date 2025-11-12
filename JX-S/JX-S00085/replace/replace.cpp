#include<bits/stdc++.h>
using namespace std;
struct node{
    string s1;
    string s2;
}a[200006];
string s,ss;
int n,q;
long long ans;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a[i].s1>>a[i].s2;
    }
    for(int i=0;i<q;i++){
        cin>>s>>ss;
        ans=0;
        for(int i=0;i<n;i++){
            int x=s.find("b");
            int y=ss.find("b");
            int x1=a[i].s1.find("b");
            int y1=a[i].s2.find("b");
            if(x1-x>=0&&x1-x==y1-y)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

