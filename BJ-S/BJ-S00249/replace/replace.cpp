#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=2e5+5;
int n,m,ans;
struct node{
    string s,t;
}a[N],q[N];
int check(string s,string t){
    if(s.find(t)>=0&&s.find(t)<s.size()) return 1;
    else return 0;
}
string th(string s,string t,int st){
    s=s.substr(0,st)+t+s.substr(st+t.size(),s.size());
    return s;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);


    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].t;
    }
    for(int i=1;i<=m;i++){
        cin>>q[i].s>>q[i].t;
        ans=0;
        for(int j=1;j<=n;j++){
            if(check(q[i].s,a[j].s)&&th(q[i].s,a[j].t,q[i].s.find(a[j].s))==q[i].t) ans++;
        }
        cout<<ans<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

