#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,q;
string s1[N];
string s2[N];

int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i];
        cin>>s2[i];
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        int cnt=0;
        int l,r;
        for(int i=0;i<t1.size();i++){
            for(int j=t1.size()-1;j>=0;j--){
                if(t1[j]!=t2[j]) {
                    r=j;
                    break;
                }
            }
            if(t1[i]!=t2[i]) {
                l=i;
                break;
            }
        }
        string x1="",x2="";
        for(int i=l+1;i<r;i++){
            x1+=t1[i];
            x2+=t2[i];
        }
        for(int i=0;i<=l;i++){
            string ch1="",ch2="";
            for(int k=i;k<=l;k++){
                ch1+=t1[k];
                ch2+=t2[k];
            }
            ch1+=x1;
            ch2+=x2;
            for(int j=r;j<t1.size();j++){
                ch1+=t1[j];
                ch2+=t2[j];
                for(int k=1;k<=n;k++){
                    if(s1[k]==ch1&&s2[k]==ch2){
                        cnt++;
                        break;
                    }
                }
            }

        }

        cout<<cnt<<endl;
    }
    return 0;
}