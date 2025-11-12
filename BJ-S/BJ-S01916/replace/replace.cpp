#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
const int M=5000000+10;
struct repl{
    string s1,s2;
    int len;
}s[N];
int n,q,nxt[M],len;
string t1,t2;
void init(int d){
    nxt[1]=0;
    for(int i=1,j=0;i<s[d].len;i++){
        while(j>0 && s[d].s1[i]!=s[d].s1[j]) j=nxt[j+1];
        if(s[d].s1[i]==s[d].s1[j]){j++;}
        nxt[i+1]=j;
    }
}
void kmp(int d){
    for(int i=1,j=0;i<len;i++){
        while(j>0 && t1[i]!=s[d].s1[j]) j=nxt[j+1];
        if(t1[i]==s[d].s1[j]){j++;}
        cout<<t1[i]<<" "<<s[d].s1[j]<<endl;
        //if(j==s[d].len)
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    int maxlen=0;
    for(int i=1;i<=n;i++){
        cin>>s[i].s1>>s[i].s2;
        s[i].len=s[i].s1.length();
        maxlen=max(maxlen,s[i].len);
    }
    while(q--){
        cin>>t1>>t2;
        len=t1.length();
        int cnt=0;
        for(int i=0;i<len;i++)
            if(t1[i]!=t2[i]) cnt++;
        /*if(cnt>maxlen){*/printf("0\n");//continue;}
        //for(int t=1;t<=n;t++){
            //memset(nxt,0,sizeof(nxt));
            //init(t);
            //kmp(t);
        //}
    }
    return 0;
}
