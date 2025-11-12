/*
 ____
/    \  This is a sugar bean.
\____/  Sugar bean don't judge your flaws.
May the God of Sugar Bean bless all OIers!
*/
#include<bits/stdc++.h>
using namespace std;
#define LL long long

LL read(){
    char ch=getchar();
    int p=1;
    LL x=0;
    while(ch<'0'||ch>'9'){
        if(ch=='-')p=-p;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*p;
}
void write(LL x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
map<pair<string,string>,LL>cnt;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    LL n,q;
    string s1,s2;
    n=read(),q=read();
    for(LL k=1;k<=n;k++){
        cin>>s1>>s2;
        LL i=-1;
        while(i+1<s1.size()&&s1[i+1]==s2[i+1])i++;
        if(i==s1.size()-1)continue;
        LL j=s1.size();
        while(j-1>=0&&s1[j-1]==s2[j-1])j--;
        s1=s1.substr(i+1,(j-1)-(i+1)+1);
        s2=s2.substr(i+1,(j-1)-(i+1)+1);
        cnt[{s1,s2}]++;
        //printf("i:%lld j:%lld ",i,j);
        //cout<<s1<<" "<<s2<<endl;
    }
    while(q--){
        cin>>s1>>s2;
        LL i=-1;
        while(i+1<s1.size()&&s1[i+1]==s2[i+1])i++;
        if(i==s1.size()-1)continue;
        LL j=s1.size();
        while(j-1>=0&&s1[j-1]==s2[j-1])j--;
        s1=s1.substr(i+1,(j-1)-(i+1)+1);
        s2=s2.substr(i+1,(j-1)-(i+1)+1);
        write(cnt[{s1,s2}]);
        putchar('\n');
    }
    return 0;
}
