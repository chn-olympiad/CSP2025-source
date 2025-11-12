#include<bits/stdc++.h>
using namespace std;
struct node{
    string x,y1,y2,z;
};
node s[200005];
int len,fro,bac;
void gt(node &s){
    string a,b;
    cin>>a>>b;
    len=a.length();
    for(fro=0;fro<len,a[fro]==b[fro];fro++);{}
    for(bac=len-1;bac>=0,a[bac]==b[bac];bac--);{}
    for(int i=0;i<fro;i++) s.x+=a[i];
    for(int i=fro;i<=bac;i++) s.y1+=a[i],s.y2+=b[i];
    for(int i=max(fro,bac+1);i<len;i++) s.z+=a[i];
}
bool cmp(node x,node y){
    if(x.y1!=y.y1) return x.y1<y.y1;
    return x.y2<y.y2;
}
int lena,lenb;
bool frt(node a,node b){
    if(a.y1!=b.y1) return 0;
    if(a.y2!=b.y2) return 0;
    lena=a.x.length();
    lenb=b.x.length();
    if(lenb>lena) return 0;
    for(int i=1;i<=lenb;i++){
        if(b.x[lenb-i]!=a.x[lena-i]) return 0;
    }
    lena=a.z.length();
    lenb=b.z.length();
    if(lenb>lena) return 0;
    for(int i=0;i<lenb;i++){
        if(b.z[i]!=a.z[i]) return 0;
    }
    return 1;
}
 void clean(node &s){
     s.x="";
     s.y1="";
     s.y2="";
     s.z="";
 }
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        gt(s[i]);
    }
    sort(s+1,s+n+1,cmp);
    node t;
    int l,r,ll,rr,mid,cnt;
    while(q--){
        gt(t);
        l=1,r=n;
        while(l<=r){
            mid=(l+r)/2;
            if(cmp(s[mid],t)) l=mid+1;
            else r=mid-1;
        }
        ll=l;
        l=1,r=n;
        while(l<=r){
            mid=(l+r)/2;
            if(cmp(t,s[mid])) r=mid-1;
            else l=mid+1;
        }
        rr=l;
        cnt=0;
        for(int i=ll;i<=rr;i++){
            if(frt(t,s[i])) cnt++;
        }
        cout<<cnt<<endl;
        clean(t);
    }
    return 0;
}
