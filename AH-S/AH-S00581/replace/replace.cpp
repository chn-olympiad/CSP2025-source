#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
struct node{
    int j1,j2;
    string s1,s2;
}s[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();
    cin>>n>>q;
    for(int j=1;j<=n;j++){
        string t1,t2;
        cin>>t1>>t2;
        int j1=0,j2=0;
        for(int i=0;i<t1.length();i++){
            if(t1[i]=='b')j1=i;
            if(t2[i]=='b')j2=i;
            if(j1&&j2)break;
        }
        s[j]={j1,j2,t1,t2};
    }
    while(q--){
        int ans=0;
        string t1,t2;
        cin>>t1>>t2;
        int j1=0,j2=0;
        for(int i=0;i<t1.length();i++){
            if(t1[i]=='b')j1=i;
            if(t2[i]=='b')j2=i;
            if(j1&&j2)break;
        }
        for(int i=1;i<=n;i++){
            if((t1.length()-j1)>=(s[i].s1.length()-s[i].j1)&&j1>=s[i].j1){
                if(s[i].j1==s[i].j2)continue;
                else if(s[i].j1<s[i].j2){
                    if(j2<j1)continue;
                    else if(j2-j1==s[i].j2-s[i].j1)ans++;
                }else{
                    if(j2>j1)continue;
                    else if(j1-j2==s[i].j1-s[i].j2)ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
