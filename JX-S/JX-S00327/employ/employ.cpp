#include<bits/stdc++.h>
using namespace std;
struct FSI{
    template<typename T>
    FSI& operator >> (T&res){
        res=0;T f=1;char ch=getchar();
        while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
        while(isdigit(ch)){res=(res*10)+(ch-48);ch=getchar();}
        res*=f;
        return *this;
    }
} scan;
const int N=505;
char s[N];
int a[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scan>>n>>m;
    scanf("%s",s);
    for(int i=1;i<=n;i++) scan>>a[i];
    vector<int> p;
    for(int i=1;i<=n;i++) p.emplace_back(i);
    int res=0;
    do{
        int cnt=0,rcnt=0;
        for(int j=0;j<n;j++){
            int c=a[p[j]];
            if(cnt>=c){
                cnt++;
                continue;
            }
            if(s[j]=='1') rcnt++;
            else cnt++;
        }
        if(rcnt>=m) res++;
    } while(next_permutation(p.begin(),p.end()));
    printf("%d",res);
    return 0;
}