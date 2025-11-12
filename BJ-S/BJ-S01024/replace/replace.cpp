#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
map<string,string> rep;
ll calc(string a,string b){
    int len1=a.size(),len2=b.size();
    if(len1!=len2) return 0;
    int t=0;
    for(int l=0;l<len1-1;l++){
        for(int r=len1-1;r;r--){
            if(r<l) continue;
            string x,y,z;
            if(l==0&&r==len1-1){
                x="",z="",y=a;
            }
            else{
                for(int i=l;~i;i--) x+=a[i];
                reverse(x.begin(),x.end());
                for(int i=r;i<len1;i++) z+=a[i];
                for(int i=l+1;i<r;i++) y+=a[i];
            }
            //cout<<x<<" "<<y<<" "<<z<<"\n";
            string ne=rep[y];
            if(ne=="") continue;
            string nne=x+ne+z;
            if(nne==b) t++; 
        }
    }
    return t;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s,t;
        cin>>s>>t;
        rep[s]=t;
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        cout<<calc(a,b)<<"\n";
    }
    return 0;
}