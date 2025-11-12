#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int dis[maxn],pos[maxn],pluss[maxn];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    string s1,s2;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        int pos1,pos2;
        for(int j=0;j<s1.length();j++){
            if(s1[j]=='b')
                pos1=j+1;
            if(s2[j]=='b')
                pos2=j+1;
        }
        pluss[i]=pos2-pos1;
        pos[i]=pos1;
        dis[i]=s1.length()+1;
    }
    for(int i=1;i<=m;i++){
        int ans=0;
        cin>>s1>>s2;
        int pos1,pos2;
        for(int j=0;j<s1.length();j++){
            if(s1[j]=='b')
                pos1=j+1;
            if(s2[j]=='b')
                pos2=j+1;
        }
        for(int k=1;k<=n;k++){
            if((pos[k]<=pos1 && pluss[k]==pos2-pos1)&&(pos1+dis[k]-pos[k])<=s1.length())
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
