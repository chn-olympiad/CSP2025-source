#include<bits/stdc++.h>
using namespace std;
int n,q,tot,t;
string s;
string sn1[200005],sn2[200005],sq1[200005],sq2[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>sn1[i]>>sn2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>sq1[i]>>sq2[i];
        if(sq1[i].size()!=sq2[i].size()){
            cout<<0<<endl;
            continue;
        }
        tot=0;
        for(int j=1;j<=n;j++){
            s=sq1[i];
            t=s.find(sn1[j]);
            if(t>=0&&t<s.size()){
                s.replace(t,sn1[j].size(),sn2[j]);
                if(s==sq2[i]){
                    tot++;
                }
            }
        }
        cout<<tot<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
