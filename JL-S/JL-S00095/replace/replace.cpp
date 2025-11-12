#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,q,ans;
bool b=true;
string s1[N],s2[N],t1,t2;
string myfind(int l,int r,string str1){
    string str;
    for(int i=l,j=0;i<=r;i++,j++) {str+=str1[i];}
    return str;
}
string getstr(int l,string str1,string str2){
    for(int i=0;i<str2.size();i++) str1[l+i]=str2[i];
    return str1;
}
struct Node{
    int c,b1=-1,b2=-1;
}l[N],t;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    for(int i=1;i<=n;i++){
            for(int j=1;j<s1[i].size();j++)
        if((s1[i][j]!='a'&&s1[i][j]!='b')||(s2[i][j]!='a'&&s2[i][j]!='b')) b=false;
    }
    b=false;
    if(b){
        for(int i=1;i<=n;i++){
            for(int j=0;j<s1[i].size();j++){
                if(s1[i][j]=='b'){
                    if(l[i].b1==-1) l[i].b1=j;
                    else {l[i].c=j-l[i].b1;l[i].b2=s1[i].size()-j-1;}
                }
            for(int j=0;j<s2[i].size();j++){
                if(s2[i][j]=='b'){
                    if(l[i].b1==-1) l[i].b1=j;
                    else {l[i].c=j-l[i].b1;l[i].b2=s2[i].size()-j-1;}
                }
            }
        }
        while(q--){
            ans=0;
            cin>>t1>>t2;
            for(int j=0;j<t1.size();j++){
                    if(t1[j]=='b'){
                        if(t.b1==-1) t.b1=j;
                        else {t.c=j-t.b1;t.b2=t1.size()-j-1;}
                    }
            }

                for(int j=0;j<t2.size();j++){
                    if(t2[j]=='b'){
                        if(t.b1==-1) t.b1=j;
                        else {t.c=j-t.b1;t.b2=t2.size()-j-1;}
                    }
                }
           for(int i=1;i<=n;i++){
               if(t.c==l[i].c&&t.b1>=l[i].b1&&t.b2>=l[i].b2) ans++;
           }
           cout<<ans<<"\n";
    }
}
    while(q--){
        ans=0;
        cin>>t1>>t2;
        for(int i=0;i<t1.size();i++){
            for(int j=1;j<=n;j++){

                if(myfind(i,i+s1[j].size()-1,t1)==s1[j]){
                    //cout<<i<<" "<<t1<<" "<<s1[j]<<"\n";
                    //cout<<getstr(i,t1,s1[j])<<" "<<t2<<"\n";
                    if(getstr(i,t1,s2[j])==t2) ans++;
                }

            }
        }
        cout<<ans<<"\n";
    }

    //cout<<getstr(3,"fyczzd","hy_");
    //cout<<myfind(0,4,"YWTDDYCF");
    return 0;
}}
