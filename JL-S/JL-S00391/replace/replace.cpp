//30
#include<bits/stdc++.h>
using namespace std;
int n,q;
struct TwoSting{
    string first;
    string second;
}s[200010];
string a,b,t;
int p,cnt;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>s[i].first>>s[i].second;
    }
    while(q--){
        cin>>a>>b;
        cnt=0;
        p=0;
        for(int i=1;i<=n;i++){
            t=a;
            p=0;
            p=t.find(s[i].first);
            if(p!=-1) t.replace(p,s[i].first.size(),s[i].second);
            if(t==b) cnt++;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
