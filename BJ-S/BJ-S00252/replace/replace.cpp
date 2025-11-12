#include <iostream>
#include <string>
#include <stdio.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#define MAXN 200003
string s[MAXN][2];
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)   cin>>s[i][0]>>s[i][1];
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        long long cnt=0;
        for(int i=1;i<=n;i++){
            string fr=s[i][0],to=s[i][1];
            //s[i][0] <- s1
            for(string::size_type j=t1.find(fr[0]);j<t1.size();j++){
                if(fr[0]!=t1[j])  continue;
                string s1=t1;
                string::size_type k=0;
                for(;k<fr.size()&&j+k<s1.size()&&fr[k]==s1[j+k];k++)s1[j+k]=to[k];
                if(k==fr.size()&&s1==t2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
