#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,q;
string s1[N],s2[N],t1,t2;
void solve1(){
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        int ans=0;
        cin>>t1>>t2;
        for(int i=1;i<=n;i++){
            int pos1=t1.find(s1[i]),pos2=t2.find(s2[i]);
            while(pos1!=-1&&pos2!=-1){
                while(pos1!=pos2&&pos1!=-1&&pos2!=-1){
                    if(pos1<pos2) pos1=t1.find(s1[i],pos1+1);
                    else pos2=t2.find(s2[i],pos2+1);
                }
                int f=1;
                for(int j=0;j<pos1;j++){
                    if(t1[j]!=t2[j]){
                        f=0;break;
                    }
                }
                for(int j=pos1+s1[i].size();j<t1.size();j++){
                    if(t1[j]!=t2[j]){
                        f=0;break;
                    }
                }
                ans+=f;
                pos1=t1.find(s1[i],pos1+1);pos2=t2.find(s2[i],pos2+1);
            }
        }
        cout<<ans<<"\n";
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    solve1();
    return 0;
}
