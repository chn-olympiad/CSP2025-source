#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        int ans=0;
        string a,b;
        cin>>a>>b;
        for(int i=1;i<=n;i++){
            string a1=a,b1=b;
            int x=a.find(s1[i]),y=b.find(s2[i]);
            while(x!=y&&x!=-1&&y!=-1){
                if(x<y){
                    a1.erase(0,x+s1[i].size());
                    x=a1.find(s1[i]);
                }else{
                    b1.erase(0,y+s2[i].size());
                    y=b1.find(s2[i]);
                }
            }
            if(x==-1||y==-1)continue;
            a1=a;
            a1.replace(x,s1[i].size(),s2[i]);
            if(a1==b)ans++;
        }
        printf("%d",ans);
    }
    return 0;
}
