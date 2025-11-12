#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    vector<string> s(2*n);
    for(int i=0;i<2*n;i++){
        cin>>s[i];
    }
    for(int i=0;i<q;i++){
        string s1,s2;
        cin>>s1>>s2;
        int cnt=0;
        for(int j=0;j<2*n;j+=2){
            string a="",b="";

            for(int l=0;l<=s1.length()-s[j].length();l++){
                if(l<s[j].length()){
                    //cout<<l<<' '<<s[j].length()<<'\n';
                    a=s1.substr(l,s[j].length());
                }else break;
                if(a==s[j])cnt++;
            }for(int l=0;l<=s2.length()-s[j+1].length();l++){
                if(l<s[j+1].length()){
                    //cout<<l<<' '<<s[j+1].length()<<'\n';
                    b=s2.substr(l,s[j+1].length());
                }else break;
                if(b==s[j+1])cnt++;
            }

        }
    cout<<cnt<<'\n';
    }
    return 0;
}
