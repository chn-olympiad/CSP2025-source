#include<bits/stdc++.h>
using namespace std;
int n,q,v[200005][2];
string s1[200005],s2[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    if(q==1) cout<<0;
    else{
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>s1[i]>>s2[i];
            int t=s1[i].find("b",0)-s2[i].find("b",0);
            if(t<0) v[-t][0]++;
            else v[t][1]++;
        }
        for(int i=1;i<=q;i++){
            string q1,q2;
            cin>>q1>>q2;
            int t2=q1.find("b",0)-q2.find("b",0);
            if(t2<0&&v[-t2][0]) cout<<v[-t2][0]<<endl;
            else if(t2>0&&v[t2][1]) cout<<v[t2][1]<<endl;
        }
    }
    return 0;
}
