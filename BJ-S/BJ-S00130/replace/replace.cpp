#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int N=1e4+5,M=6e5+5;
int n,m[2]={1,1},q,st,en,ans;
bool flag;
string s1,s2;
struct Node{
    int ch[27];
    vector <int> e;
}tr[M][2];
void insert(string s,int id,int t){
    int pos=0;
    for(int i=0;i<s.size();i++){
        if(tr[pos][t].ch[s[i]-'a']==0)tr[pos][t].ch[s[i]-'a']=++m[t];
        pos=tr[pos][t].ch[s[i]-'a'];
        //if(id==37312)cout << s[i]<<" "<<pos<<endl;
    }
    //cout << id<<" "<<pos<<" "<<t<<endl;
    tr[pos][t].e.push_back(id);
}
void deal(vector <int> &a,vector <int>&b){
    if(a.size()==0||b.size()==0)return ;
    int l1=a.size(),l2=b.size(),c1=0,c2=0;
    while(c1<a.size()&&c2<b.size()){
        while(a[c1]<b[c2])c1++;
        if(a[c1]==b[c2]){
            ans++;
        }
        c2++;
    }
}
void search(int x){
    int p1=0,p2=0;
    while(x<s1.size()){
       p1=tr[p1][0].ch[s1[x]-'a'],p2=tr[p2][1].ch[s2[x]-'a'];
       if(p1==0||p2==0)return ;
       if(x>=en)deal(tr[p1][0].e,tr[p2][1].e);
       x++;
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        insert(s1,i,0);
        insert(s2,i,1);
        //if(i==5169||i==17284||i==19780||i==26516||i==26975||i==37312)cout <<s1<<endl<<s2<<endl<<m[0]<<" "<<m[1]<<endl;
    }
    for(int i=1;i<=q;i++){
        cin>>s1>>s2;
        //if(i==666||i==1729||i==5530||i==6376||i==12278||i==24457)flag=0;
        if(s1.size()!=s2.size()){
            cout << 0 << endl;
            continue;
        }
        st=-1,en=-1;
        for(int j=0;j<s1.size();j++){
            if(s1[j]!=s2[j])en=j;
            if(s1[j]==s2[j]&&en<0)st=j;
        }
        //cout << st<<" "<<en<<endl;
        ans=0;
        for(int j=0;j<=st+1;j++){
            search(j);
            //cout << j<<" "<<ans<<endl;
        }
        if(flag){
            cout <<s1<<endl<<s2<<endl;
            cout << st<<" "<<en<<endl;
            cout << ans<<endl;
        }
        cout << ans << endl;
        flag=0;

    }
}
