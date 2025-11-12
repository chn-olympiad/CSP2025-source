#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
namespace FileIO{
    void Test(string s){
        freopen((s+".in").c_str(),"r",stdin);
        freopen("test.out","w",stdout);
    }
    void File(string s){
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}
int n,m;
char s[10005];
int c[10005],p[10005];
void Work(){
    cin>>n>>m;
    cin>>s+1;
    bool a1=1;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(s[i]=='0') a1=0;
    }
    if(n<=10){
        for(int i=1;i<=n;i++){
            p[i]=i;
        }
        int ans=0;
        do{
            int fnt=0,snt=0;
            for(int i=1;i<=n;i++){
                if(fnt>=c[p[i]]){
                    fnt++;
                    continue;
                }
                if(s[i]=='0') fnt++;
                else snt++; 
            }
            if(snt>=m) ans++;
        }while(next_permutation(p+1,p+n+1));
        printf("%d\n",ans);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // FileIO::Test("replace/replace3");
    FileIO::File("employ");
    int t=1;
    // scanf("%d",&t);
    while(t--){
        Work();
    }
    clog<<clock()*1.0/CLOCKS_PER_SEC;
    return 0;
}
/*
g++ test.cpp -o test -fsanitize=address,undefined -g
g++ test.cpp -o test -O2
3 2
101
1 1 2
*/