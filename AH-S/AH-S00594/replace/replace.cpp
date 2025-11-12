#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
int n,q;
string s1[200100];
string s2[200100];
string t1[200100];
string t2[200100];
int ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    int posb1[200010],posb2[200010];
    for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<s1[i].size();j++){
            if(s1[i][j]=='b')posb1[i]=j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<s2[i].size();j++){
            if(s2[i][j]=='b')posb2[i]=j;
        }
    }
    int ans;
    for(int i=1;i<=q;i++)cin>>t1[i]>>t2[i];
    for(int i=1;i<=q;i++){
        ans=0;
        int posbt1,posbt2;
        for(int j=0;j<t1[i].size();j++){
            if(t1[i][j]=='b')posbt1=j;
        }
        for(int j=0;j<t2[i].size();j++){
            if(t2[i][j]=='b')posbt2=j;
        }
        for(int k=1;k<=n;k++){
            if(((posb1[k]-posb2[k]==posbt1-posbt2&&(posbt1>=posb1[k]&&posbt2>=posb2[k]))&&(t1[i].size()-posbt1>=s1[k].size()-posb1[k]&&t2[i].size()-posbt2>=s1[k].size()-posb2[k]))&&t1[i].size()-t2[i].size()==s1[k].size()-s2[k].size())ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//DE BG6CNI
//CSP-S TNX! 73!
