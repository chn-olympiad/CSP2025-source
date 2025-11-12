#include<iostream>
using namespace std;
const int N=2e5+5;
struct node{
    int val;
    int l,r;
}s[N];
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        int res;
        for(int j=0;j<a.length();j++){
            if(a[j]=='b'){
                s[i].l=j;
                s[i].r=a.length()-j-1;
                res=j;
            }
        }
        for(int j=0;j<b.length();j++){
            if(b[j]=='b'){
                s[i].val=j-res;
            }
        }
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        int res;
        int ln,rn,vn;
        for(int i=0;i<a.length();i++){
            if(a[i]=='b'){
                ln=i;
                rn=a.length()-i-1;
                res=i;
            }
        }
        for(int i=0;i<b.length();i++){
            if(b[i]=='b'){
                vn=i-res;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(s[i].l<=ln&&s[i].r<=rn&&s[i].val==vn)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
