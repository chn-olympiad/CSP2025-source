#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
int n,q,t[200005],n1,n2;
char s1[5000005],s2[5000005];
unordered_map<int,int> hsh1,hsh2;
vector<int> v1[200005],v2[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        scanf("%s%s",s1+1,s2+1);
        int l=strlen(s1+1),st=0,ed=0;
        for(int j=1;j<=l;j++){
            if(s1[j]!=s2[j]){
                st=j;
                break;
            }
        }
        for(int j=l;j>=1;j--){
            if(s1[j]!=s2[j]){
                ed=j;
                break;
            }
        }
        if(st==0){
            i--,n--;
            continue;
        }
        ll hsh=0;
        for(int j=ed;j>=1;j--){
            hsh=(hsh*997+(s1[j]-'a')*26+s2[j]-'a')%mod;
        }
        if(!hsh1[hsh]) hsh1[hsh]=++n1;
        v1[hsh1[hsh]].push_back(i);
        hsh=0;
        for(int j=st;j<=l;j++){
            hsh=(hsh*997+(s1[j]-'a')*26+s2[j]-'a')%mod;
        }
        if(!hsh2[hsh]) hsh2[hsh]=++n2;
        v2[hsh2[hsh]].push_back(i);
    }
    for(int i=1;i<=q;i++){
        scanf("%s%s",s1+1,s2+1);
        int l=strlen(s1+1),l2=strlen(s2+1);
        if(l!=l2){
            puts("0");
            continue;
        }
        int st=0,ed=0;
        for(int j=1;j<=l;j++){
            if(s1[j]!=s2[j]){
                st=j;
                break;
            }
        }
        for(int j=l;j>=1;j--){
            if(s1[j]!=s2[j]){
                ed=j;
                break;
            }
        }
        ll hsh=0;
        int ans=0;
        for(int j=ed;j>=st;j--){
            hsh=(hsh*997+(s1[j]-'a')*26+s2[j]-'a')%mod;
        }
        if(hsh1[hsh]){
            int x=hsh1[hsh];
            for(int y:v1[x]){
                t[y]=i;
            }
        }
        for(int j=st-1;j>=1;j--){
            hsh=(hsh*997+(s1[j]-'a')*26+s2[j]-'a')%mod;
            if(hsh1[hsh]){
                int x=hsh1[hsh];
                for(int y:v1[x]){
                    t[y]=i;
                }
            }
        }
        hsh=0;
        for(int j=st;j<=ed;j++){
            hsh=(hsh*997+(s1[j]-'a')*26+s2[j]-'a')%mod;
        }
        if(hsh2[hsh]){
            int x=hsh2[hsh];
            for(int y:v2[x]){
                if(t[y]==i){
                    ans++;
                }
            }
        }
        for(int j=ed+1;j<=l;j++){
            hsh=(hsh*997+(s1[j]-'a')*26+s2[j]-'a')%mod;
            if(hsh2[hsh]){
                int x=hsh2[hsh];
                for(int y:v2[x]){
                    if(t[y]==i){
                        ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
5
x y z
a b c

x

n/2
*/
