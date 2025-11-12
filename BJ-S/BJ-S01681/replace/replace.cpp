#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    map<string,string>a;
    int n,q,x=0;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        a[s1]=s2;
    }
    for(int i=1;i<=q;i++){
        string t1,t2;
        cin>>t1>>t2;
        int tl1=t1.size(),tl2=t2.size();
        for(int l=0;l<n;l++){
            for(int r=l;r<=n;r++){
                string s1,s2;
                for(int j=l;j<=r;j++){
                    s1+=t1[j];
                    s2+=t2[j];
                }
                if(a[s1]==s2) x++;
            }
        }
        cout<<x<<"\n";
    }
    return 0;
}
