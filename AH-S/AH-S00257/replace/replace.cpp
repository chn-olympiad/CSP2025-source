#include<bits/stdc++.h>
using namespace std;
struct Node{
    int pre=0,nxt=0;
};
int n,q;
Node t1,t2,s1[200005],s2[200005],ch[200005];
string s;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;true;j++){
            if(s[j]=='b'){
                s1[i].pre=i;
                break;
            }
        }
        s1[i].nxt=s.length()-s1[i].pre-2;
        cin>>s;
        for(int j=0;true;j++){
            if(s[j]=='b'){
                s2[i].pre=i;
                break;
            }
        }
        s2[i].nxt=s.length()-s2[i].pre-2;
        ch[i].pre=s2[i].pre-s1[i].pre,ch[i].nxt=s2[i].nxt-s1[i].nxt;
    }
    while(q--){
        cin>>t1>>t2;
        int now_pre,now_nxt,tar_pre,tar_nxt,ans=0;
        for(int i=0;true;i++){
            if(t1[i]=='b'){
                now_pre=i;
                break;
            }
        }
        now_nxt=t1.length()-now_pre-2;
        for(int i=0;true;i++){
            if(t2[i]=='b'){
                tar_pre=i;
                break;
            }
        }
        tar_nxt=t2.length()-tar_pre-2;
        for(int i=1;i<=n;i++){
            if(now_pre+ch[i].pre==tar_pre&&now_nxt+ch[i].nxt==tar_pre){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
