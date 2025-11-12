#include<bits/stdc++.h>
using namespace std;
int n,q,bsum,len[200001],v[500001];
string s[200001][2],s1,s2;
vector<int> nex[200001];
void solve1(){
    while(q--){
        cin>>s1>>s2;
        int l=s1.size(),pos=0,ans=0,vnum=0;
        for(int i=0;i<l;i++){
            if(s1[i]!=s2[i]){
                v[i]=1;
                vnum++;
            }
            else
                v[i]=0;
        }
 /*       for(int i=1;i<=n;i++){
            bool flag=0;
            int last=vnum;
            for(int j=0;j<l;j++){
                if(s1[j]==s[i][0][pos+1]){
                    pos++;
                    if(pos==len[i]-1){
                        for(int x=j,y=pos;y>=0;x--,y--){
                            if(s[i][1][y]!=s2[x]){
                                flag=1;
                                break;
                            }
                            if(v[x])
                                last--;
                        }
                        pos=nex[i][pos];
                    }
                }
                else
                    pos=nex[i][pos];
                if(flag)
                    break;
            }
            if(!flag && !last)
                ans++;
        }*/
        printf("%d\n",ans);
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d\n",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        len[i]=s[i][0].size();
        for(int i=0,l=0;i<len[i];i++){
            if(s[i][0][l]=='b')
                bsum++;
            if(s[i][0][l]==s[i][0][i] && i!=l)
                nex[i].push_back(++l);
            else{
                l=0;
                nex[i].push_back(0);
            }
        }
    }
    if(bsum!=n)
        solve1();
    return 0;
}

