#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
struct node{
    int v;
    int w;
}a[500005], b[500005];
int bk=0;

bool f[500005];

// x 异或 y
int Xor(int x, int y){
    string s_x="", s_y="", r="";
    while(x>0){
        s_x+=x%2+'0';
        x/=2;
    }
    while(y>0){
        s_y+=y%2+'0';
        y/=2;
    }
    for(int i=0; i<min(s_x.size(), s_y.size()); i++){
        if(s_x[i]==s_y[i]) r+='0';
        else r+='1';
    }
    for(int i=min(s_x.size(), s_y.size()); i<max(s_x.size(), s_y.size()); i++){
        if(s_x.size()>s_y.size()) r+=s_x[i];
        else r+=s_y[i];
    }

    int res=0;
    for(int i=0; i<r.size(); i++)
        res+=(r[i]-'0')*pow(2, i);
    return res;
}

bool cmp(node a, node b){
    return a.w-a.v<b.w-b.v;
}

bool isOK(int x){
    for(int i=1; i<=n; i++){
        if( f[i]==1 && ( b[x].v<=i && b[x].w>=i ) ) return false;
    }
    return true;
}

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i].v;

    for(int i=1; i<=n; i++){
        int t=0;
        for(int j=i; j<=n; j++){
            t=Xor(t, a[j].v);
            if(t==k){
                b[bk++]={i, j};
                break;
            }
        }
    }
    sort(b, b+bk, cmp);

    for(int i=0; i<bk; i++){
        if(isOK(i)) ans++;
        for(int j=b[i].v; j<=b[i].w; j++) f[j]=1;
    }
    cout<<ans<<endl;

    return 0;
}
