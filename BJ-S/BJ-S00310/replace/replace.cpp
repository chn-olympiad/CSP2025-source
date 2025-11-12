#include <bits/stdc++.h>
using namespace std;
const int MAXLEN = 5e6 + 5;
const int MAXN = 2e5 + 5;
int n,q;
int len[MAXN];
char t1[MAXLEN],t2[MAXLEN];
bool vis1[MAXN],vis2[MAXN];

struct AC{
    int trie[MAXLEN][26];
    int fail[MAXLEN];
    int ncnt = 1;
    vector<int> End[MAXLEN];

    void insert(const char *str,int id){
        int p = 1;
        for (int i = 0;str[i];i ++){
            int &nxt = trie[p][str[i] - 'a'];
            if (!nxt)nxt = ++ncnt;
            p = nxt;
        }
        End[p].push_back(id);
    }

    void bfs(){
        // printf("AC:\n");
        // for (int i = 1;i <= ncnt;i ++)
        //     for (int j = 0;j < 26;j ++)
        //         if (trie[i][j])printf("%d -%c-> %d\n",i,j + 'a',trie[i][j]);
        queue<int> q;
        fail[1] = 1;
        for (int i = 0;i < 26;i ++){
            if (trie[1][i])q.push(trie[1][i]),fail[trie[1][i]] = 1;
            else trie[1][i] = 1;
        }
        while (q.size()){
            int x = q.front();
            q.pop();
            // printf("extend %d\n",x);
            for (int i = 0;i < 26;i ++){
                if (trie[x][i]){
                    fail[trie[x][i]] = trie[fail[x]][i];
                    q.push(trie[x][i]);
                }else trie[x][i] = trie[fail[x]][i];
            }
        }

        // for (int i = 1;i <= ncnt;i ++)printf("fail %d = %d\n",i,fail[i]);
    }
};
AC a1,a2;

int main(){
    #ifndef kevin
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    #endif
    scanf("%d%d",&n,&q);
    for (int i = 1;i <= n;i ++){
        scanf("%s%s",t1,t2);
        a1.insert(t1,i),a2.insert(t2,i);
        len[i] = strlen(t1);
    }
    a1.bfs(),a2.bfs();
    while (q --){
        scanf("%s%s",t1 + 1,t2 + 1);
        int fst = 0x3f3f3f3f,lst = -1;
        int len = strlen(t1 + 1);
        if ((int)strlen(t2 + 1) != len){
            printf("0\n");
            continue;
        }
        for (int i = 1;i <= len;i ++)
            if (t1[i] != t2[i]){
                if (fst == 0x3f3f3f3f)fst = i;
                lst = i;
            }
        // printf("fst %d lst %d\n",fst,lst);
        int p1 = 1,p2 = 1;
        int ans = 0;
        for (int i = 1;i <= len;i ++){
            p1 = a1.trie[p1][t1[i] - 'a'];
            p2 = a2.trie[p2][t2[i] - 'a'];
            if (i < lst)continue;
            int f1 = p1,f2 = p2;
            for (int i = 1;i <= n;i ++)vis1[i] = vis2[i] = false;
            while (f1 != 1){
                // printf("f1 %d\n",f1);
                for (auto it : a1.End[f1])vis1[it] = true;
                f1 = a1.fail[f1];
            }
            while (f2 != 1){
                // printf("f2 %d\n",f2);
                for (auto it : a2.End[f2])vis2[it] = true;
                f2 = a2.fail[f2];
            }
            
            for (int j = 1;j <= n;j ++){
                if (vis1[j] && vis2[j] && i - ::len[j] + 1 <= fst){
                    ans ++;
                    // printf("pos %d valid %d %d\n",i,j,::len[j]);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}