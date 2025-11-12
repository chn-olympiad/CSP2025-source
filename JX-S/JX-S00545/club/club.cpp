#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read();
void write(ll x);
const int N=1e5+10;
int n;
int a[N][4];
int main(){
    //update file name!!!
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--){
        n=read();
        vector<int> pos[4];
        ll ans=0;
        for(int i=1;i<=n;i++){
            int t=0;
            for(int j=1;j<=3;j++){
                a[i][j]=read();
                if(!t||a[i][t]<a[i][j]) t=j;
            }
            ans+=a[i][t];
            pos[t].push_back(i);
        }
        int k=0;
        for(int i=1;i<=3;i++){
            if(pos[i].size()>n/2) k=i;
        }
        if(k){  
            vector<int> res;
            for(auto i:pos[k]){
                int m1=0,m2=0;
                for(int j=1;j<=3;j++){
                    if(a[i][j]>m1) m2=m1,m1=a[i][j];
                    else if(a[i][j]>m2) m2=a[i][j];
                }
                res.push_back(m1-m2);
            }
            sort(res.begin(),res.end());
            int cnt=res.size();
            for(int i=0;i<res.size();i++){
                if(cnt==n/2) break;
                ans-=res[i];
                cnt--;
            }
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void write(ll x){
    if(x<0) x=-x,putchar('-');
    if(x>9) write(x/10);
    putchar(x%10+'0');
}