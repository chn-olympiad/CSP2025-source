#include<bits/stdc++.h>
using namespace std;
struct fun{
    string s1,s2;
}a[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].s1>>a[i].s2;
    }
    string s,st;
    for(int i=1;i<=q;i++){
        cin>>s>>st;
        int ans=0;
        for(int j=1;j<=n;j++){
            int r=s.find(a[j].s1,0);
            //cout<<s<<" "<<a[j].s1<<" "<<r<<endl;
            if(r!=-1){
                string m=s;
                m.replace(r,a[j].s1.size(),a[j].s2);
                //cout<<m<<" ";
                if(m==st){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
