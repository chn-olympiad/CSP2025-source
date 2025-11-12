#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;

int n,q;
int ans = 0;

struct node{
    char s1[2005];
    char s2[2005];
    int sl1=0;
    int sl2=0;
};
node a[maxn];
string t1;
string t2;
string t3;

int si1(int x){
    for(int i = 1; ;i++){
        if(a[x].s1[i]==0)
            return i;
    }
}

int si2(int x){
    for(int i = 1; ;i++){
        if(a[x].s2[i]==0)
            return i;
    }
}

bool pd(int l,int r,int x){
    bool bo;
    for(int i=l;i<=r;i++){
        if(t1[i]==a[x].s1[i-l]) bo=1;
        else return 0;
    }
    return 1;
}

void re(int l,int r,int x){
    for(int i=l;i<=r;i++){
        t3[i]=a[x].s2[i-l];
    }
}

bool pd2(int l,int r,int x){
    for(int i=l;i<=r;i++){
        if(t3[i]!=t2[i]) return 0;
    }
    return 1;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i].s1;
        cin >> a[i].s2;
    }
    for(int j=1;j<=n;j++){
        a[j].sl1=si1(j);
        a[j].sl2=si2(j);
    }
    for(int i=1;i<=q;i++){
        ans=0;
        cin >> t1;
        cin >> t2;
        // cout << t1;
        int l1 = t1.size();
        int l2 = t2.size();
        // cout << l1 << " " << l2 << endl;
        for(int l=1;l<=n;l++){
            for(int j=0;j<=l1-a[l].sl1;j++){
                if(pd(j,j+a[l].sl1,l)){
                    for(int k=0;k<l1;k++)
                        t3[k]=t1[k];
                    re(j,j+a[l].sl1,l);
                    if(pd2(j,j+a[l].sl1,l))
                        ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}