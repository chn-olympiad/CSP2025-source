#include<bits/stdc++.h>
#define N 200010
using namespace std;
int n,q;
struct D{
    int pos,len,pos1,pos2;
}del[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        int pos1=-1,pos2=-1;
        cin>>s1;
        cin>>s2;
        int len=s1.size();
        for(int i=0;i<len;i++){
            if(s1[i]=='b') pos1=i;
            if(s2[i]=='b') pos2=i;
            if(pos1!=-1&&pos2!=-1) break;
        }
        del[i].pos2=pos2;
        del[i].pos1=pos1;
        del[i].pos=pos2-pos1;
        del[i].len=len;
    }
    while(q--){
        string s1,s2;
        int ans=0;
        int pos1=-1,pos2=-1;
        cin>>s1;
        cin>>s2;
        int len=s1.size();
        for(int i=0;i<len;i++){
            if(s1[i]=='b') pos1=i;
            if(s2[i]=='b') pos2=i;
            if(pos1!=-1&&pos2!=-1) break;
        }
        for(int i=1;i<=n;i++){
            if(del[i].pos==pos2-pos1&&del[i].len<=len&&pos1>=del[i].pos1&&(del[i].len-del[i].pos2)<=len-pos2) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
