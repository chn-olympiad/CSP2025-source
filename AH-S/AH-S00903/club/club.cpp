#include <bits/stdc++.h>
using namespace std;
int read(){
    int xx=0,ff=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') ff=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        xx=xx*10+(ch-'0');
        ch=getchar();
    }
    return xx*ff;
}
void write(int xx){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10) write(xx/10);
    putchar(xx%10+'0');
}
const int N=1e5;
int n,a[N+5][3];
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;++i){
            for(int j=0;j<=2;++j) a[i][j]=read();
        }
        vector<vector<int> > v(3);
        int ans=0;
        for(int i=1;i<=n;++i){
            int j=0;
            if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2]) j=0;
            else if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2]) j=1;
            else j=2;
            v[j].push_back(i);
            ans+=a[i][j];
        }
        int w=max(v[0].size(),max(v[1].size(),v[2].size()));
        if(w>n/2){
            int p=0;
            for(int i=0;i<=2;++i){
                if((int)(v[i].size())==w){
                    p=i;
                    break;
                }
            }
            vector<int> d;
            for(auto x:v[p]){
                int i=0,j=1;
                if(p==0) i=1,j=2;
                else if(p==1) i=0,j=2;
                else i=0,j=1;
                d.push_back(a[x][p]-max(a[x][i],a[x][j]));
            }
            sort(d.begin(),d.end());
            w-=n/2;
            for(int i=0;i<w;++i) ans-=d[i];
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}