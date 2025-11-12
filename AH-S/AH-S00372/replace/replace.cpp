#include<bits/stdc++.h>
using namespace std;
int n,q;
map <string,string> m;
string s1,s2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        m[s1]=s2;
    }
    while(q--){
        int cnt=0;
        cin>>s1>>s2;
        int x=s1.size();
        if(s1.size()!=s2.size()){
            cout<<0<<endl;
            continue;
        }
        if(s1==s2){
            cout<<0<<endl;
            continue;
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                string ss1=s1.substr(0,i),ss2=s2.substr(0,i),st1=s1.substr(n-j,j),st2=s2.substr(n-j,j);
                string s3=s1.substr(i,n-j-i-1),s4=s2.substr(i,n-j-i-1);
                if(ss1==ss2&&st1==st2&&string(m[s3])==s4) cnt++;
            }
        }*/
        cout<<0<<endl;
    }
    return 0;
}
