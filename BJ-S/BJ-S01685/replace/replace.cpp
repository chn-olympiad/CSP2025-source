#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,q;
string a[N],b[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        int len=s1.length();
        int ans=0;
        for(int i=1;i<=n;i++){
            int flagg=0;
            for(int j=0;j<len;j++){
                    //cout<<i<<" "<<j<<endl;
                int flag=1;
                for(int k=0;k<j;k++){
                    if(s1[k]!=s2[k])flag=0;
                }
            //cout<<flag<<" ";
                for(int k=0,p=j;k<a[i].length();k++,p++){
                    if(p>=len){
                        flag=0;
                        break;
                    }
                    if(a[i][k]==s1[p]&&b[i][k]==s2[p])continue;
                    else flag=0;
                }
                //cout<<flag<<" ";
                for(int k=j+a[i].length();k<len;k++){
                    if(s1[k]!=s2[k])flag=0;
                }
                //cout<<flag<<" ";
                if(flag)flagg=1;
                //cout<<endl;
            }
            ans+=flagg;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

