#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int n,qq;
struct node{
    string s1,s2;
}q[MAXN];
string clip(string s,int l,int r){
    string ss="";
    for(int i=l;i<=r;i++)ss+=s[i];
    return ss;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>qq;
    for(int i=1;i<=n;i++)cin>>q[i].s1>>q[i].s2;
    while(qq--){
        int ans=0;
        string s1,s2;
        cin>>s1>>s2;
        if(s1.size()!=s2.size()){
            cout<<0<<endl;
            continue;
        }else{
            int l=INT_MAX,r=-1;
            for(int i=0;i<s1.size();i++){
                    if(s1[i]!=s2[i]){
                        l=min(l,i);
                        r=max(r,i);
                        //cout<<l<<' '<<r<<endl;
                    }
            }
            for(int i=l;i>=0;i--){
                for(int j=r;j<=s1.size();j++){
                    string ss1=clip(s1,i,j),ss2=clip(s2,i,j);
                    //cout<<ss1<<' '<<ss2<<'!'<<endl;
                    for(int i=1;i<=n;i++){
                        node* qqq=new node;
                        qqq->s1=ss1,qqq->s2=ss2;
                        if(q[i].s1==qqq->s1&&q[i].s2==qqq->s2){
                            ans++;
                            delete qqq;
                            break;
                        }
                        delete qqq;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
