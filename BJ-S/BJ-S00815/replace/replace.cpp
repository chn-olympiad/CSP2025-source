#include<bits/stdc++.h>
using namespace std;
int n,q,pos,ans,l,r,len;
string s1,s2,s3;
struct dict{
    string a,b;
}d[100010];
bool pd(string a,string b){
    int l=a.size();
    for(int i=0;i<l;i++){
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>d[i].a>>d[i].b;
    }
    while(q--){
        cin>>s1>>s2;
        ans=0;
        l=-1,r=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                r=i;
                if(l=-1) l=i;
            }
        }
        len=r-l+1;
        for(int i=1;i<=n;i++){
            pos=0;
            if(d[i].a.size()!=d[i].b.size()||d[i].a.size()<len) continue;
            while(1){
                if(s1.find(d[i].a,pos)==-1) break;
                s3=s1;
                pos=s1.find(d[i].a,pos);
                for(int j=pos;j<pos+d[i].a.size();j++){
                    s3[j]=d[i].b[j-pos];
                }
                if(pd(s3,s2)) ans++;
                pos++;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
