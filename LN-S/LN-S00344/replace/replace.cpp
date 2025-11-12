#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
const int base=26,mod=1e9+7;
int n,q,len;
string s1[maxn],s2[maxn],t1,t2,pp,qq;
int ans,len1,len2;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        cin>>t1>>t2;
        ans=0;
        len1=t1.size();
        len2=t2.size();
        for(int i=1;i<=n;i++){
            for(int j=0;j<len1;j++){
                if(j+s1[i].size()>len1) break;


                if(t1.substr(j,s1[i].size())!=s1[i]) continue;
                string stt=t1.substr(0,j);
                stt+=s2[i];
                stt+=t1.substr(j+s1[i].size());
                //cout<<stt<<endl;
                if(stt==t2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
void wk(string &a,string &b){
    len=a.size();
    int st=0,ed=len-1;
    for(int i=0;i<len;i++){
        if(a[i]!=b[i]) break;
        st++;
    }
    for(int i=len-1;i>=st;i--){
        if(a[i]!=b[i]) break;
        ed--;
    }
    pp=qq="";
    for(int i=st;i<=ed;i++){
        pp+=a[i],qq+=b[i];
    }
    a=pp,b=qq;
}
/////
#include<bits/stdc++.h>
#define int long long
using namespace std;
string
void wk(char &s1[],char &s2[]){
    len=strlen(s1);
    st=0,ed=len-1;
    for(int i=0;i<len;i++){
        if(s1[i]!=s2[i]) break;
        st++;
    }
    for(int i=len-1;i>=st;i--){
        if(s1[i]!=s2[i]) break;
        ed--;
    }
    for(int i=st;i<=ed;i++){
        st1[cnt]=s1[i];
        st2[cnt]=s2[i];
        cnt++;
    }
    s1=st1;
    s2=st2;
}
char s1[maxn],s2[maxn],t1[maxn],t2[maxn];
int n,q;
signed main(){
    scanf("%d%d",&n,&q);
    scanf("%s%s",&s1,&s2);
    for(int i=1;i<=n;i++){
        scanf("%s%s",&t1[i],&t2[i]);
    }
    wk(s1,s2);
    cout<<s1<<" "<<s2<<endl;

    return 0;
}
*/
