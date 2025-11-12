#include<bits/stdc++.h>
using namespace std;
const int N=200010;
string a[N],b[N];
bool ifin(string s1,string s2,string aj,string bj){
    for(int i=0;i<s1.size();i++){
        string s=s1;
        int bo=0;
        if(i+aj.size()-1<=s1.size()){
            for(int j=0;j<aj.size();j++){
                if(s1[i+j]!=aj[j]){
                    bo=1;
                    break;
                }
                s[i+j]=bj[j];
            }
        }else{
            continue;
        }
        if(bo) continue;
        for(int j=0;j<s.size();j++){
            if(s[j]!=s2[j]) return false;
        }
        return true;
    }
    return false;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=q;i++){
        int ans=0;
        string s1,s2;
        cin>>s1>>s2;
        string d1="",d2="";
        for(int j=1;j<=n;j++){
            if(ifin(s1,s2,a[j],b[j])) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}


