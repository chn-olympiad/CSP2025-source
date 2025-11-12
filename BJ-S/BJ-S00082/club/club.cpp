#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull long long
#define pb push_back
#define mk make_pair
#define fr first
#define se second
int read(){
    int n=0,fl=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-') fl=-1; 
        c=getchar();
    }
    while(isdigit(c)) n=n*10+c-'0',c=getchar();
    return n*fl;
}
void write(int n){
    if(n<0) putchar('-'),n=-n;
    int c[100]={},len=0;
    while(n) c[++len]=n%10,n/=10;
    for(int i=len;i;i--) putchar(c[i]+'0');
}
void writesp(int n){write(n),putchar(' ');}
void writeln(int n){write(n),putchar('\n');}
const int N=1e5+5;
int a[N][3],d[N],ans,cnt[3];
vector<int>wrk;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,n;
    T=read();
    while(T--){
        n=read(); ans=0;
        for(int i=0;i<3;i++) cnt[i]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++) a[i][j]=read();
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) d[i]=0;
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) d[i]=1;
            else d[i]=2;
            ans+=a[i][d[i]];
            cnt[d[i]]++;
        }
        int p=-1;
        if(cnt[0]>n/2) p=0;
        if(cnt[1]>n/2) p=1;
        if(cnt[2]>n/2) p=2;
        if(p!=-1){
            wrk.clear();
            for(int i=1;i<=n;i++){
                if(d[i]!=p) continue;
                int tmp=0;
                for(int j=0;j<3;j++){
                    if(j==p) continue;
                    tmp=max(tmp,a[i][j]);
                }
                wrk.push_back(a[i][p]-tmp);
            }
            sort(wrk.begin(),wrk.end());
            for(int i=0;i<cnt[p]-n/2;i++) ans-=wrk[i];
        }
        writeln(ans);
    }
    return 0;
}