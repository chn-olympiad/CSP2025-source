#include<bits/stdc++.h>
using namespace std;
struct st{
    string a,b,qj,hj;
}s[200005];
int n,q;
string sa[200005],sb[200005],c,d;
map<string,bool>mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>sa[i]>>sb[i];
        string sm=sa[i]+'.'+sb[i];
        if(mp[sm]||sa[i]==sb[i]){
            continue;
        }
        mp[sm]=true;
        int x,y;
        for(int j=0;j<sa[i].size();j++){
            if(sa[i][j]==sb[i][j]){
                s[i].qj+=sa[i][j];
            }
            else {
                x=j;
                break;
            }
        }
        for(int j=sa[i].size()-1;j>=0;j--){
            if(sa[i][j]==sb[i][j]){
                s[i].hj=sa[i][j]+s[i].hj;
            }
            else {
                y=j;
                break;
            }
        }
        for(int j=x;j<=y;j++){
            s[i].a+=sa[i][j];
            s[i].b+=sb[i][j];
        }
    }
    while(q--){
        cin>>c>>d;
        if(c.size()!=d.size()){
            cout<<0<<'\n';
            continue;
        }
        string qqj,qhj,rc,rd;
        int x,y;
        for(int i=0;i<c.size();i++){
            if(c[i]==d[i]){
                qqj+=c[i];
            }
            else {
                x=i;
                break;
            }
        }
        for(int i=c.size()-1;i>=0;i--){
            if(c[i]==d[i]){
                qhj=c[i]+qhj;
            }
            else {
                y=i;
                break;
            }
        }
        for(int i=x;i<=y;i++){
            rc+=c[i];
            rd+=d[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(rc==s[i].a&&rd==s[i].b){
                if(qqj==s[i].qj&&qhj==s[i].hj){
                    ans++;
                }
                else {
                    int p1=qqj.size()-1,p2=s[i].qj.size()-1,p3=0,p4=0;
                    int lc=qhj.size()-1,ld=s[i].hj.size()-1;
                    if(p1<p2||lc<ld){
                        continue;
                    }
                    bool flag=true;
                    while(p2>=0){
                        if(s[i].qj[p2]!=qqj[p1]){
                            flag=false;
                            break;
                        }
                        p2--;
                        p1--;
                    }
                    while(p4<ld){
                        if(s[i].hj[p4]!=qhj[p3]){
                            flag=false;
                            break;
                        }
                        p3++;
                        p4++;
                    }
                    if(flag){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
