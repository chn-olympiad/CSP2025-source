#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>
void in(T &x){
    char c=getchar(); int f=1; x=0;
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    x*=f;
}
const int N=100010;
int t,n;
int a[3][N],tag[N],cnt[3];
int getmax(int a,int b,int c){
    if(a>=b&&a>=c) return 0;
    else if(b>=a&&b>=c) return 1;
    else return 2;
}
vector<int> b;
void work(){
    in(n);
    cnt[0]=cnt[1]=cnt[2]=0; b.clear();
    int ans=0;
    for(int i=1;i<=n;i++){
        in(a[0][i]); in(a[1][i]); in(a[2][i]);
        tag[i]=getmax(a[0][i],a[1][i],a[2][i]);
        cnt[tag[i]]++; ans+=a[tag[i]][i];
    }
    int x=getmax(cnt[0],cnt[1],cnt[2]);
    if(cnt[x]>n/2){
        for(int i=1;i<=n;i++){
            if(tag[i]==x){
                int res=INT_MAX;
                for(int j=0;j<3;j++){
                    if(j==x) continue;
                    res=min(res,a[x][i]-a[j][i]);
                }
                b.push_back(res);
            }
        }
        sort(b.begin(),b.end());
        for(int i=0;i<cnt[x]-n/2;i++)
            ans-=b[i];
    }
    printf("%d\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    in(t);
    while(t--) work();
    return 0;
}