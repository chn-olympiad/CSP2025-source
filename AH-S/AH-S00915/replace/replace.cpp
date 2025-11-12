#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n,qq;
string t1,t2,bbbbbb;
struct node{
    string a;
    string ch,chh;
    int st;
}s[200005];
map<string,int> mapp;
bool check(string s1,string s2,int t,int p){
    int start=0;
    while(true){
        start=s1.find(s2,start);
        if(start==-1) break;
        if(start+p==t) return true;
        start+=1;
    }
    return false;
}
bool cmp(node x,node y){
    return x.ch<y.ch;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>qq;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>bbbbbb;
        int q,p;
        for(int j=0;j<s[i].a.length();j++){
            if(s[i].a[j]!=bbbbbb[j]){
                q=j;
                break;
            }
        }
        for(int j=s[i].a.length()-1;j>=0;j--){
            if(s[i].a[j]!=bbbbbb[j]){
                p=j;
                break;
            }
        }
        s[i].ch=s[i].a.substr(q,p-q+1);
        s[i].chh=bbbbbb.substr(q,p-q+1);
        s[i].st=q;
    }
    sort(s+1,s+1+n,cmp);
    mapp[s[1].ch]=1;
    for(int i=2;i<=n;i++){
        if(s[i].ch!=s[i-1].ch){
            mapp[s[i].ch]=i;
        }
    }
    while(qq--){
        cin>>t1>>t2;
        if(t1.length()!=t2.length()){
            cout<<0<<endl;
            continue;
        }
        int p,q;
        for(int i=0;i<t1.length();i++){
            if(t1[i]!=t2[i]){
                p=i;
                break;
            }
        }
        for(int i=t1.length()-1;i>=0;i--){
            if(t1[i]!=t2[i]){
                q=i;
                break;
            }
        }
        int ans=0;
        string t=t1.substr(p,q-p+1);
        string tt=t2.substr(p,q-p+1);
        for(int i=mapp[t];i<=n;i++){
            if(t!=s[i].ch) break;
            if(tt==s[i].chh&&check(t1,s[i].a,p,s[i].st)){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
