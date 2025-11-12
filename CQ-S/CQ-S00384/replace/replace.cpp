#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX=1e4+20,NAX=1e6+10,mod=1e9+7;
int n,q;
string s1[MAX],s2[MAX];
string t1,t2;
int ans=0;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin >> s1[i] >> s2[i];}
    for(int i=1;i<=q;i++){
        cin >> t1 >> t2;
        ans=0;
        for(int j=1;j<=n;j++){
            int l=t1.find(s1[j]);
            if(l==string::npos){continue;}
            int r=l+s1[j].size();
            string x=t1.substr(0,l),z=t1.substr(r);
            string newt1=x+s2[j]+z;
            if(newt1==t2){ans++;}
        }printf("%d\n",ans);
    }
    return 0;
}