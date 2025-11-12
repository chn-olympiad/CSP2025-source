#include <bits/stdc++.h>
using namespace std;

void read(int &x){
    x=0;int f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    x*=f;
}
const int N=5e5+10;
int n,k;
int a[N],s[N];
struct Q{
    int l,r;
};
vector<Q>p;
bool cmp(Q x,Q y){
    if(x.r==y.r) return x.l<y.l;
    return x.r<y.r;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    read(n),read(k);
    bool subtaskA=true,subtaskB=true;
    for(int i=1;i<=n;i++){
        read(a[i]);
        if(a[i]>1) {
            subtaskA=false;
            subtaskB=false;
        }
        else {
            if(a[i]==0){
                subtaskA=false;
            }
        }
    }
    if(subtaskA){
        if(k==1){
            cout<<n;
            return 0;
        }
        if(k!=0){
            cout<<0;
            return 0;
        }
        cout<<n/2;
        return 0;
    }
    else if(subtaskB){
        if(k==1){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    cnt++;
                }
            }
            cout<<cnt;
        }
        else if(k==0){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0) cnt++;
            }
            for(int i=1;i<=n;){
                if(a[i]==1){
                    int l=i;
                    while(i<=n&&a[i]==1){
                        i++;
                    }
                    int len=i-l;
                    if(len%2==0) cnt++;
                }
                else i++;
            }
            cout<<cnt;
        }
        return 0;
    }
        for(int i=1;i<=n;i++){
            s[i]=s[i-1]^a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if((s[j]^s[i-1])==k){
                    p.push_back({i,j});
                }
            }
        }
        sort(p.begin(),p.end(),cmp);
        int ans=0,maxn=1;
        for(int i=0;i<p.size();i++){
            maxn=1;
            int last=p[i].l;
            for(int j=i-1;j>=0;j--){
                if(p[j].r<last) maxn++,last=p[j].l;
            }
            last=p[i].r;
            for(int j=i+1;j<p.size();j++){
                if(p[j].l>last) maxn++,last=p[j].r;
            }
            ans=max(ans,maxn);
        }
        cout<<ans;

    return 0;
}
