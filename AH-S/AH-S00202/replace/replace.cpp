#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
string t1,t2,s1[2000005],s2[2000005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        bool flag=true;
        for(int j=1;j<=n&&flag;j++){
            int l=0;
            while(true){
                int e=t1.find(s1[j],l);
                if(e==-1) break;
                string x=t1.substr(0,e),z=t1.substr(e+s1[j].size());
                //cout<<x<<" "<<s2[j]<<" "<<z<<" "<<t2<<"\n";
                if(x+s2[j]+z==t2) cnt++;
                l=e+1;

            }

        }
        cout<<cnt<<"\n";
        cnt=0;
    }
    return 0;
}
