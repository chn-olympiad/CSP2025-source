#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[200005],s2[200005],t1,t2,p1,p2,p3;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        ans=0;
        for(int l=0;l<t1.size();l++){
            for(int r=l;r<t1.size();r++){
                p1="";
                p2="";
                p3="";
                for(int j=0;j<l;j++){
                    p1=p1+t1[j];
                }
                for(int j=l;j<=r;j++){
                    p2=p2+t1[j];
                }
                for(int j=r+1;j<t1.size();j++){
                    p3=p3+t1[j];
                }
                for(int i=1;i<=n;i++){
                    if(p2==s1[i]){
                        if(p1+s2[i]+p3==t2){
                            ans++;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}