#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream f("replace.in");
    ofstream g("replace.out");
    int n,q,l,ans;
    f>>n>>q;
    string s1[n],s2[n],t1,t2;
    for (int i=0;i<n;i++){
        f>>s1[i]>>s2[i];
    }
    for (int i=0;i<q;i++){
        ans=0;
        f>>t1>>t2;
        if (t1.length()!=t2.length()) g<<0<<endl;
        else{
            l=t1.length();
            for (int j=0;j<l;j++){
                for (int k=j;k<l;k++){
                    for (int m=0;m<n;m++){
                        if (t1.substr(j,k-j+1)==s1[m]){
                            if (t1.substr(0,j)+s2[m]+t1.substr(min(l-1,k+1),l-k-1)==t2) ans++;
                        }
                    }
                }
            }
            g<<ans<<endl;
        }
    }
}