#include<bits/stdc++.h>
using namespace std;
map<string,string> s;
string s1,s2,s3,s4,s5,s6;
int n,m,ans;
void work(string s1,string s2){
    int x,y,z;
    string xx,yy,zz;
    int len1 = s1.size();
    for(int i=0;i<len1;i++){
        for(int j=i;j<=len1;j++){
            if(i>0) for(int k=0;k<i;k++) s3+=s1[k];//front(x)
            for(int k=i;k<j;k++) s4+=s1[k];//middle(y)
            if(j<len1) for(int k=j;k<len1;k++) s5+=s1[k];//back(z)
            //cout<<s3<<"|"<<s4<<"|"<<s5<<endl;
            map<string,string>::iterator it;
            for(it=s.begin();it!=s.end();it++){
                if(s4==it->first){
                    s6 = it->second;
                    if(s3+s6+s5==s2) ans++;
                }
            }
            s3="",s4="",s5="";
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        s.insert({s1,s2});
    }
    for(int i=1;i<=m;i++){
        cin>>s1>>s2;
        work(s1,s2);
        cout<<ans<<endl;
        ans = 0;
    }
    return 0;
}
