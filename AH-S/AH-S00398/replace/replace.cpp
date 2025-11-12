#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int V=26;
int dif_len[200010];
int lst1[200010],lst2[200010],id1[5000010],id2[5000010],trie1[5000010][V],trie2[5000010][V],tot1=1,tot2=1;
bool flag[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        int len=s1.size(),minp=0x3f3f3f3f,maxp=-0x3f3f3f3f;
        for(int j=0;j<len;j++){
            if(s1[j]!=s2[j]){
                minp=min(minp,j);
                maxp=max(maxp,j);
            }
        }
        if(minp==0x3f3f3f3f  &&  maxp==-0x3f3f3f3f){
            continue ;
        }
        dif_len[i]=maxp-minp+1;
        int pre1=1;
        for(int j=minp;j<=maxp;j++){
            int cmd=s1[j]-'a';
            if(!trie1[pre1][cmd]){
                trie1[pre1][cmd]=++tot1;
            }
            pre1=trie1[pre1][cmd];
        }
        for(int j=minp;j<len;j++){
            int cmd=s2[j]-'a';
            if(!trie1[pre1][cmd]){
                trie1[pre1][cmd]=++tot1;
            }
            pre1=trie1[pre1][cmd];
        }
        lst1[i]=id1[pre1];
        id1[pre1]=i;
        int pre2=1;
        for(int j=maxp;j>=minp;j--){
            int cmd=s2[j]-'a';
            if(!trie2[pre2][cmd]){
                trie2[pre2][cmd]=++tot2;
            }
            pre2=trie2[pre2][cmd];
        }
        for(int j=maxp;j>=0;j--){
            int cmd=s1[j]-'a';
            if(!trie2[pre2][cmd]){
                trie2[pre2][cmd]=++tot2;
            }
            pre2=trie2[pre2][cmd];
        }
        lst2[i]=id2[pre2];
        id2[pre2]=i;
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0<<"\n";
            continue;
        }
        int len=t1.size(),minp=0x3f3f3f3f,maxp=-0x3f3f3f3f;
        for(int j=0;j<len;j++){
            if(t1[j]!=t2[j]){
                minp=min(minp,j);
                maxp=max(maxp,j);
            }
        }
        int pre1,pre2;
        bool ok1,ok2;
        ok1=true;
        pre1=1;
        for(int j=minp;ok1  &&  j<=maxp;j++){
            int cmd=t1[j]-'a';
            if(!trie1[pre1][cmd]){
                ok1=false;
                break;
            }
            pre1=trie1[pre1][cmd];
            int tmp=id1[pre1];
            while(tmp){
                if(maxp-minp+1==dif_len[tmp]){
                    flag[tmp]=true;
                }
                tmp=lst1[tmp];
            }
        }
        for(int j=minp;ok1  &&  j<len;j++){
            int cmd=t2[j]-'a';
            if(!trie1[pre1][cmd]){
                ok1=false;
                break;
            }
            pre1=trie1[pre1][cmd];
            int tmp=id1[pre1];
            while(tmp){
                if(maxp-minp+1==dif_len[tmp]){
                    flag[tmp]=true;
                }
                tmp=lst1[tmp];
            }
        }
        int ans=0;
        ok2=true;
        pre2=1;
        for(int j=maxp;ok2  &&  j>=minp;j--){
            int cmd=t2[j]-'a';
            if(!trie2[pre2][cmd]){
                ok2=false;
                break;
            }
            pre2=trie2[pre2][cmd];
            int tmp=id2[pre2];
            while(tmp){
                if(maxp-minp+1==dif_len[tmp]  &&  flag[tmp]){
                    ans++;
                }
                tmp=lst2[tmp];
            }
        }
        for(int j=maxp;ok2  &&  j>=0;j--){
            int cmd=t1[j]-'a';
            if(!trie2[pre2][cmd]){
                ok2=false;
                break;
            }
            pre2=trie2[pre2][cmd];
            int tmp=id2[pre2];
            while(tmp){
                if(maxp-minp+1==dif_len[tmp]  &&  flag[tmp]){
                    ans++;
                }
                tmp=lst2[tmp];
            }
        }
        ok1=true;
        pre1=1;
        for(int j=minp;ok1  &&  j<=maxp;j++){
            int cmd=t1[j]-'a';
            if(!trie1[pre1][cmd]){
                ok1=false;
                break;
            }
            pre1=trie1[pre1][cmd];
            int tmp=id1[pre1];
            while(tmp){
                if(maxp-minp+1==dif_len[tmp]){
                    flag[tmp]=false;
                }
                tmp=lst1[tmp];
            }
        }
        for(int j=minp;ok1  &&  j<len;j++){
            int cmd=t2[j]-'a';
            if(!trie1[pre1][cmd]){
                ok1=false;
                break;
            }
            pre1=trie1[pre1][cmd];
            int tmp=id1[pre1];
            while(tmp){
                if(maxp-minp+1==dif_len[tmp]){
                    flag[tmp]=false;
                }
                tmp=lst1[tmp];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
